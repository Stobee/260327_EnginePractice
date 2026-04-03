#include "Monster.h"
#include "GameplayStatics.h"
#include "Engine.h"
#include "World.h"
#include "ResourceManager.h"
#include "SpriteComponent.h"
#include "CollisionComponent.h"

AMonster::AMonster(int InX, int InY, char InMesh, int InHP, int InAP)
{
	X = InX;
	Y = InY;
	
	SpriteComponent = CreateDefaultSubObject<USpriteComponent>("Sprite");

	Resource TempResource = GEngine->GetResourceManager()->LoadTexture("Assets/monster.bmp", true, 255, 255, 255);
	SpriteComponent->Image = TempResource.Image;
	SpriteComponent->Texture = TempResource.Texture;
	SpriteComponent->ZOrder = 200;
	

	CollisionComponent = CreateDefaultSubObject<UCollisionComponent>("Collision");
	
	CollisionComponent->bIsGenerateOverlap = true;
}

AMonster::~AMonster()
{
}

void AMonster::BeginPlay()
{
}

void AMonster::Tick()
{
	__super::Tick();

	ElapsedTime += UGameplayStatics::GetWorldDeltaSeconds();

	if (ElapsedTime >= ExecutionTime)
	{
		ElapsedTime = 0;

		int Direction = rand() % 5;

		if (Direction == 0 && PredictMove(X, Y - 1))
		{
			Y--;
		}
		if (Direction == 1 && PredictMove(X, Y + 1))
		{
			Y++;
		}
		if (Direction == 2 && PredictMove(X - 1, Y))
		{
			X--;
		}
		if (Direction == 3 && PredictMove(X + 1, Y))
		{
			X++;
		}
	}

}

