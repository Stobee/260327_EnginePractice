#pragma once
#include "Component.h"
#include "RenderableComponent.h"

#include "SDL.h"

class USpriteComponent : public UComponent, public IRenderableComponent 
{public:
	USpriteComponent();
	~USpriteComponent();

	virtual void BeginPlay() override;

	virtual void Tick() override;

	// IRenderableComponent ±¸Çö
	virtual void Render() override;

	int ZOrder = 0;

	

	SDL_Surface* Image;
	SDL_Texture* Texture;
};

