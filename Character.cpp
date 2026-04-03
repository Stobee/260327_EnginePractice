#include "Character.h"
#include "Engine.h"
#include "World.h"
#include "CollisionComponent.h"

ACharacter::ACharacter()
{
}

ACharacter::~ACharacter()
{
}

bool ACharacter::PredictMove(int InX, int InY)
{
	// 월드내 액터를 가져와서 비교
	for (auto Other : GEngine->GetWorld()->GetAllActors())
	{
		if (Other == this) // 자기 자신은 비교할 필요가 없음
		{
			continue;
		}
		for (auto OtherComponent : Other->GetComponents())
		{
			UCollisionComponent* OtherCollision = dynamic_cast<UCollisionComponent*>(OtherComponent);
			if (OtherCollision)
			{
				if (OtherCollision->bIsGenerateHit && InX == Other->GetX() && InY == Other->GetY())
				{
					ReceiveHit(Other);
					return false;
				}
				//if (OtherCollision->bIsGenerateOverlap && InX == Other->GetX() && InY == Other->GetY())
				//{ReceiveOverlap(Other);return false;}
			}
		}
	}


	return true;
}