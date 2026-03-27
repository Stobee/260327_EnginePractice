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

	void LoadMap(std::string MapName);

	inline std::vector<AActor*>& GetAllActors()
	{
		return Actors;
	}


	void Tick();
	void Render();

	
protected:
	std::vector<AActor*> Actors;
};

