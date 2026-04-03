#pragma once

#include "Actor.h"

#include <vector>
#include <string>




class UWorld
{public:
	UWorld();
	~UWorld();

	template <typename T>
	AActor* SpawnActorToLocation(int InX, int InY)
	{
		AActor* NewActor = new T;
		Actors.push_back(NewActor);

		NewActor->SetActorLocation(InX, InY);

		return NewActor;
	}

	template<typename T>
	AActor* GetActorOfClass()
	{
		for (auto Actor : Actors)
		{
			T* Target = dynamic_cast<T*>(Actor);
			if (Target)
			{
				return Target;
			}
		}

		return nullptr;
	}

	void LoadMap(std::string MapName);

	inline std::vector<AActor*>& GetAllActors()
	{
		return Actors;
	}

	void BeginPlay();
	void Tick();
	void Render();

	
protected:
	std::vector<AActor*> Actors;
	void Sort();
};

