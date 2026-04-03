#pragma once

#include <string>
#include <vector>
#include <functional>

using FActorBeginOverlapSignature = std::function<void(class AActor*)>;

struct SDL_Surface;
struct SDL_Texture;

class UComponent;

class AActor
{public: 
	AActor(int InX = 0, int InY = 0, char InMesh = ' ');
	virtual ~AActor();

	virtual void BeginPlay();
	virtual void Tick();
	

	void SetActorLocation(int InX, int InY);


	inline const std::vector<UComponent*> GetComponents() 
	{
		return Components;
	}

	inline const int GetX()const 
	{
		return X;
	}

	inline const int GetY()const
	{
		return Y;
	}

	inline const std::string& GetName() const
	{
		return Name;
	}
	FActorBeginOverlapSignature OnActorBeginOverlap;

	virtual void ReceiveHit(class AActor* Other);
protected:
	int X;
	int Y;

	std::string Name;

	std::vector<UComponent*> Components;

	template<typename T>
	T* CreateDefaultSubObject(std::string ComponentName) 
	{
		T* Temp = new T;
		Temp->Owner = this;
		Components.push_back(Temp);

		return Temp;
	}


};

