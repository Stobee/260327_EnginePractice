#include "Player.h"
#include "Engine.h"
#include "GameplayStatics.h"
#include "ResourceManager.h"

APlayer::APlayer(int InX, int InY, char InMesh, int InHP, int InAP)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	ZOrder = 100;
	R = 255;
	G = 0;
	B = 0;
	Resource TempResource = GEngine->GetResourceManager()->LoadTexture("Assets/player.bmp", true, 255, 0, 255);
	Image = TempResource.Image;
	Texture = TempResource.Texture;
}

APlayer::~APlayer()
{
}


void APlayer::Render()
{
	int TileSize = 30;
	int SpriteSizeX = Image->w / 5;
	int SpriteSizeY = Image->h / 5;
	
	SDL_Event Event = GEngine->GetEvent();

	SDL_Rect SourceRect = { SpriteSizeX * SpriteIndexX, SpriteSizeY * SpriteIndexY, SpriteSizeX, SpriteSizeY };
	SDL_Rect DestinationRect = { X * TileSize, Y * TileSize, TileSize, TileSize };
	SDL_RenderCopy(GEngine->GetRenderer(), Texture, &SourceRect, &DestinationRect);
}

void APlayer::Tick()
{
	__super::Tick();

	SDL_Event Event = GEngine->GetEvent();

	if (Event.type == SDL_KEYDOWN)
	{
		SDL_Keycode KeyCode = Event.key.keysym.sym;
		if (KeyCode == SDLK_w)
		{
			Y--;
			SpriteIndexY = 2;
			SpriteIndexX = 0;
		}
		if (KeyCode == SDLK_s)
		{
			Y++;
			SpriteIndexY = 3;
			SpriteIndexX = 0;
		}
		if (KeyCode == SDLK_a)
		{
			X--;
			SpriteIndexY = 0;
			SpriteIndexX = 0;
		}
		if (KeyCode == SDLK_d)
		{
			X++;
			SpriteIndexY = 1;
			SpriteIndexX = 0;
		}
		if (KeyCode == SDLK_ESCAPE)
		{
			GEngine->Stop();
		}

	}

	ElapsedTime += UGameplayStatics::GetWorldDeltaSeconds();
	if (ElapsedTime >= ExecutionTime)
	{
		SpriteIndexX++;
		SpriteIndexX = SpriteIndexX % 5;
		ElapsedTime = 0;
	}
}


