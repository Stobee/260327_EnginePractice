#include "World.h"
#include "Engine.h"
#include "Actor.h"

#include "Wall.h"
#include "Floor.h"
#include "Player.h"
#include "Monster.h"
#include "Goal.h"

#include <fstream>
#include <string>
#include <algorithm>


UWorld::UWorld()
{
}

UWorld::~UWorld()
{
	for (auto Actor : Actors)
	{
		delete Actor;
	}
	Actors.clear();
}

void UWorld::LoadMap(std::string MapName)
{
	std::ifstream MapStream(MapName);
	int Y = 0;
	int MaxX = -1;
	int MaxY = -1;

	while (!MapStream.eof())
	{
		std::string Line;
		std::getline(MapStream, Line);
		for (int X = 0; X < Line.length(); ++X)
		{
			if (Line[X] == '#')
			{	
				SpawnActorToLocation<AWall>(X,Y);
				SpawnActorToLocation<AFloor>(X,Y);
			}
			else if (Line[X] == ' ')
			{
				SpawnActorToLocation<AFloor>(X,Y);
			}
			else if (Line[X] == 'M')
			{	
				SpawnActorToLocation<AMonster>(X,Y);
				SpawnActorToLocation<AFloor>(X,Y);
			}
			else if (Line[X] == 'G')
			{
				SpawnActorToLocation<AGoal>(X,Y);
				SpawnActorToLocation<AFloor>(X, Y);
			}
			else if (Line[X] == 'P')
			{
				SpawnActorToLocation<APlayer>(X, Y);
				SpawnActorToLocation<AFloor>(X, Y);
			}
			if (MaxX < X + 1)
			{
				MaxX = X + 1;
			}
			
			
		}
		Y++;

	}

	MaxY = Y;

	SDL_SetWindowSize(GEngine->GetWindow(),(MaxX) * 30, MaxY * 30);

	std::sort(Actors.begin(), Actors.end(),
		[](AActor* First, AActor* Second) -> int {
			return (First->GetZOrder() < Second->GetZOrder() ? 1 : 0);
		});
}



void UWorld::Tick()
{
	for (auto Actor : Actors)
	{
		Actor->Tick();
	}

}
void UWorld::Render()
{
	GEngine->Clear();

	for (auto Actor : Actors)
	{
		Actor->Render();
	}

	GEngine->Flip();
}


void UWorld::Sort()
{
	for (int i = 0; i < Actors.size(); i++)
	{
		for (int j = 0; j < Actors.size(); j++)
		{
			if (Actors[i]->GetZOrder() < Actors[j]->GetZOrder())
			{
				auto Temp = Actors[i];
				Actors[i] = Actors[j];
				Actors[j] = Actors[i];
			}
		}
	}
}
