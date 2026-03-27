#pragma once
#include "Actor.h"
class AWall : public AActor
{public:
	AWall(int X = 0, int Y = 0, char Mesh = '#');
	virtual ~AWall();
};

