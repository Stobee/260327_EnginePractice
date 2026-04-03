#pragma once
#include "Character.h"

class USpriteComponent;
class UCollisionComponent;

class AMonster : public ACharacter
{
public:
	AMonster(int X = 0, int Y = 0, char Mesh = 'M', int HP = 10, int AP = 1);
	virtual ~AMonster();

	virtual void BeginPlay() override;
	virtual void Tick() override;
	USpriteComponent* SpriteComponent;
	UCollisionComponent* CollisionComponent;

protected:
	float ElapsedTime = 0;
	float ExecutionTime = 0.1f;
	
};

