#include "Engine.h"
#include "World.h"
#include "Actor.h"

#include <conio.h>


UEngine* UEngine::Instance = nullptr;

int UEngine::KeyboardInput = 0;

UEngine::UEngine()
{
	Init();
}

UEngine::~UEngine()
{
	Term();
}

void UEngine::Init()
{	
	bIsRunning = true;
	World = new UWorld();
}

void UEngine::Term()
{
	delete World;
	World = nullptr;
}

void UEngine::Run()
{
	while (bIsRunning)
	{
		Input();
		Tick();
		Render();
	}

}

void UEngine::Input()
{
	KeyboardInput = _getch();
}


void UEngine::Tick()
{
	World->Tick();
}

void UEngine::Render()
{
	World->Render();
}

