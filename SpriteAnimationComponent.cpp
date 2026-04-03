#include "SpriteAnimationComponent.h"
#include "Engine.h"
#include "GameplayStatics.h"
#include "Actor.h"

USpriteAnimationComponent::USpriteAnimationComponent()
{
}

USpriteAnimationComponent::~USpriteAnimationComponent()
{
}

void USpriteAnimationComponent::Tick()
{
	__super::Tick();
	ElapsedTime += UGameplayStatics::GetWorldDeltaSeconds();
	if (ElapsedTime >= ExecutionTime)
	{
		SpriteIndexX++;
		SpriteIndexX = SpriteIndexX % 5;
		ElapsedTime = 0;
	}
}

void USpriteAnimationComponent::Render()
{
	
	int TileSize = 30;
	int SpriteSizeX = Image->w / 5;
	int SpriteSizeY = Image->h / 5;

	SDL_Event Event = GEngine->GetEvent();

	SDL_Rect SourceRect = { SpriteSizeX * SpriteIndexX, SpriteSizeY * SpriteIndexY, SpriteSizeX, SpriteSizeY };
	SDL_Rect DestinationRect = { Owner->GetX() * TileSize, Owner->GetY() * TileSize, TileSize, TileSize };
	SDL_RenderCopy(GEngine->GetRenderer(), Texture, &SourceRect, &DestinationRect);
}
