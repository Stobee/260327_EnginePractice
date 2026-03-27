#include "World.h"
#include "Actor.h"

#include "Wall.h"
#include "Floor.h"
#include "Player.h"
#include "Monster.h"
#include "Goal.h"

#include <fstream>
#include <string>

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

	while (!MapStream.eof())
	{
		std::string Line;
		std::getline(MapStream, Line);
		for (int X = 0; X < Line.length(); ++X)
		{
			if (Line[X] == '#')
			{
				SpawnActorToLocation<AWall>(X,Y);
			}
			else if (Line[X] == ' ')
			{
				SpawnActorToLocation<AFloor>(X,Y);
			}
			else if (Line[X] == 'M')
			{
				SpawnActorToLocation<AMonster>(X,Y);
			}
			else if (Line[X] == 'G')
			{
				SpawnActorToLocation<AGoal>(X,Y);
			}
			else if (Line[X] == 'P')
			{
				SpawnActorToLocation<APlayer>(X, Y);
			}
			
		}
		Y++;
	}

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
	for (auto Actor : Actors)
	{
		Actor->Render();
	}
}