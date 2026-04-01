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
	SDL_Event Event = GEngine->GetEvent();

	if (Event.type == SDL_KEYDOWN)
	{
		SDL_Keycode KeyCode = Event.key.keysym.sym;
		if (KeyCode == SDLK_w)
		{
			Y--;
			// Callback
			// Turn to std::function<void>
		}
		if (KeyCode == SDLK_s)
		{
			Y++;
		}
		if (KeyCode == SDLK_a)
		{
			X--;
		}
		if (KeyCode == SDLK_d)
		{
			X++;
		}
		if (KeyCode == SDLK_ESCAPE)
		{
			GEngine->Stop();
		}

	}
}

void ACharacter::Render()
{
	__super::Render();
}

void ACharacter::ApplyDamage(ACharacter* Other)
{
}


