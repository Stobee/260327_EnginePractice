#pragma once
#include "Actor.h"

struct SDL_Surface;
struct SDL_Texture;

class AGameMode : public AActor
{public:
	AGameMode();
	virtual ~AGameMode();

	virtual void Tick() override; 

	void GameOver();
	void GameComplete();

	SDL_Surface* TextSurface;

};

