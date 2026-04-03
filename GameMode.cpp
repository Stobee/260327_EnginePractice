#include "GameMode.h"
#include "Player.h"
#include "Monster.h"
#include "Goal.h"
#include "Engine.h"
#include "World.h"

#include "SDL_ttf.h"


AGameMode::AGameMode()
{
}

AGameMode::~AGameMode()
{
}

void AGameMode::Tick()
{
	__super::Tick();

	
}

void AGameMode::GameOver()
{
	static bool bGameOver = false;

	if (!bGameOver)
	{
		SDL_Log("Game Over");
		bGameOver = true;
	}
}

void AGameMode::GameComplete()
{
	static bool bGameComplte = false;

	if (!bGameComplte)
	{
		SDL_Log("Game Complete");

		bGameComplte = true;
	}
}
