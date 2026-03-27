#include "Character.h"
#include "Engine.h"

ACharacter::ACharacter(int InX, int InY, char InMesh, int InHP, int InAP)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	HP = InHP;
	AP = InAP;
	ZOrder = 10;
}

ACharacter::~ACharacter()
{
}

void ACharacter::BeginPlay()
{
}

void ACharacter::Tick()
{
	__super::Tick();

	if (UEngine::KeyboardInput == 'w'|| UEngine::KeyboardInput == 'W')
	{
		Y--;
	}
	if (UEngine::KeyboardInput == 's'|| UEngine::KeyboardInput == 'S')
	{
		Y++;
	}
	if (UEngine::KeyboardInput == 'a' || UEngine::KeyboardInput == 'A')
	{
		X--;
	}
	if (UEngine::KeyboardInput == 'd' || UEngine::KeyboardInput == 'D')
	{
		X++;
	}

	UEngine::KeyboardInput = 0;
}

void ACharacter::Render()
{
	__super::Render();
}

void ACharacter::ApplyDamage(ACharacter* Other)
{
}


