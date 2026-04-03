#pragma once
#include "Actor.h"

class USpriteComponent;

class AFloor : public AActor
{public:
	AFloor(int X = 0, int Y = 0, char Mesh = ' ');
	virtual ~AFloor();

	USpriteComponent* SpriteComponent;

};

