#pragma once
#include "Actor.h"
class ACharacter : public AActor
{public:
	ACharacter(int X = 0, int Y = 0, char Mesh = ' ', int HP = 0, int AP = 0);
	virtual ~ACharacter() override;

	virtual void BeginPlay() override;

	virtual void Tick() override;

	virtual void Render() override;

	void ApplyDamage(ACharacter* Other);

	

protected:
	int HP;
	int AP;
};

