#include "Floor.h"
#include "Engine.h"
#include "ResourceManager.h"
#include "SpriteComponent.h"

AFloor::AFloor(int InX, int InY, char InMesh)
{
	X = InX;
	Y = InY;
	
	// 컴포넌트 붙임
	SpriteComponent = CreateDefaultSubObject<USpriteComponent>("Sprite");
	
	Resource TempResource = GEngine->GetResourceManager()->LoadTexture("Assets/floor.bmp");
	SpriteComponent->Image = TempResource.Image;
	SpriteComponent->Texture = TempResource.Texture;
	SpriteComponent->ZOrder = 1;

	Name = "Floor";
}

AFloor::~AFloor()
{
}
