#pragma once
#include "Actor.h"
class APlayer : public AActor
{public: 
	APlayer(int X = 0, int Y = 0, char Mesh = 'P', int HP = 100, int AP = 5);
	virtual ~APlayer();

	virtual void Render() override;
	virtual void Tick() override;

protected:
	int SpriteIndexX = 0;
	int SpriteIndexY = 0;

	float ElapsedTime = 0;
	float ExecutionTime = 0.1f;
};

