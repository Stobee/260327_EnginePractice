#include "Monster.h"
#include "GameplayStatics.h"
#include "Engine.h"
#include "ResourceManager.h"

AMonster::AMonster(int InX, int InY, char InMesh, int InHP, int InAP)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	ZOrder = 50;
	R = 255;
	G = 255;
	B = 0;

	Resource TempResource = GEngine->GetResourceManager()->LoadTexture("Assets/monster.bmp", true, 255, 255, 255);
	Image = TempResource.Image;
	Texture = TempResource.Texture;
}

AMonster::~AMonster()
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

		if (Direction == 0)
		{
			Y--;
		}
		if (Direction == 1)
		{
			Y++;
		}
		if (Direction == 2)
		{
			X--;
		}
		if (Direction == 3)
		{
			X++;
		}
	}

}
