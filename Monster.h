#pragma once
#include "Actor.h"
class AMonster : public AActor
{
public:
	AMonster(int X = 0, int Y = 0, char Mesh = 'M', int HP = 10, int AP = 1);
	virtual ~AMonster();


	virtual void Tick() override;

protected:
	float ElapsedTime = 0;
	float ExecutionTime = 0.1f;
};

