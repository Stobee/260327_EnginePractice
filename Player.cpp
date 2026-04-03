#include "Player.h"
#include "Engine.h"
#include "World.h"
#include "Goal.h"
#include "Monster.h"
#include "GameplayStatics.h"
#include "GameMode.h"
#include "ResourceManager.h"
#include "SpriteAnimationComponent.h"
#include "CollisionComponent.h"

APlayer::APlayer(int InX, int InY, char InMesh, int InHP, int InAP)
{
	X = InX;
	Y = InY;
	
	SpriteAnimationComponent = CreateDefaultSubObject<USpriteAnimationComponent>("Sprite");
	
	
	Resource TempResource = GEngine->GetResourceManager()->LoadTexture("Assets/player.bmp", true, 255, 0, 255);
	SpriteAnimationComponent->Image = TempResource.Image;
	SpriteAnimationComponent->Texture = TempResource.Texture;
	SpriteAnimationComponent->ZOrder = 300;
	SpriteAnimationComponent->ExecutionTime = 0.15f;

	CollisionComponent = CreateDefaultSubObject<UCollisionComponent>("Collision");
	CollisionComponent->bIsGenerateHit = true;
	CollisionComponent->bIsGenerateOverlap = true;
}

APlayer::~APlayer()
{
}



void APlayer::BeginPlay()
{
	__super::BeginPlay();

	OnActorBeginOverlap = [&](AActor* Other) -> void {
		AGoal* Goal = dynamic_cast<AGoal*>(Other);
		if (Goal)
		{
			AGameMode* GM = UGameplayStatics::GetGameMode();
			if (GM)
			{
				GM->GameComplete();
			}
		}

		AMonster* Monster = dynamic_cast<AMonster*>(Other);
		if (Monster)
		{
			AGameMode* GM = UGameplayStatics::GetGameMode();
			if (GM)
			{
				GM->GameOver();
			}
		}
		};
}

void APlayer::Tick()
{
	__super::Tick();

	SDL_Event Event = GEngine->GetEvent();

	if (Event.type == SDL_KEYDOWN)
	{
		SDL_Keycode KeyCode = Event.key.keysym.sym;
		if (KeyCode == SDLK_w && PredictMove(X, Y - 1))
		{
			Y--;
			SpriteAnimationComponent->SpriteIndexY = 2;
			SpriteAnimationComponent->SpriteIndexX = 0;
		}
		if (KeyCode == SDLK_s && PredictMove(X, Y + 1))
		{
			Y++;
			SpriteAnimationComponent->SpriteIndexY = 3;
			SpriteAnimationComponent->SpriteIndexX = 0;
		}
		if (KeyCode == SDLK_a && PredictMove(X - 1, Y))
		{
			X--;
			SpriteAnimationComponent->SpriteIndexY = 0;
			SpriteAnimationComponent->SpriteIndexX = 0;
		}
		if (KeyCode == SDLK_d && PredictMove(X + 1, Y))
		{
			X++;
			SpriteAnimationComponent->SpriteIndexY = 1;
			SpriteAnimationComponent->SpriteIndexX = 0;
		}
		if (KeyCode == SDLK_ESCAPE)
		{
			GEngine->Stop();
		}

	}

}

void APlayer::ProcessBeginOverlap(AActor* OtherActor)
{
}



void APlayer::ReceiveHit(AActor* Other)
{
}


