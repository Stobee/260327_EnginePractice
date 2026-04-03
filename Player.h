#pragma once
#include "character.h"

class USpriteAnimationComponent;
class UCollisionComponent;
class APlayer : public ACharacter
{public: 
	APlayer(int X = 0, int Y = 0, char Mesh = 'P', int HP = 100, int AP = 5);
	virtual ~APlayer();

	virtual void BeginPlay() override;
	virtual void Tick() override;
	virtual void ReceiveHit(class AActor* Other) override;
	virtual void ProcessBeginOverlap(class AActor* OtherActor);
	
	

	
	USpriteAnimationComponent* SpriteAnimationComponent;
	UCollisionComponent* CollisionComponent;

	

protected:
	
};

