#pragma once
#include "Actor.h"
class AGoal : public AActor
{public:
	AGoal(int X = 0, int Y = 0, char Mesh = 'G');
	virtual ~AGoal();
};

