#include "Actor.h"
#include "Engine.h"

#include <Windows.h>
#include <iostream>

AActor::AActor(int InX, int InY, char InMesh) : X(InX), Y(InY), Mesh(InMesh)
{
	R = 0;
	G = 0;
	B = 0;
	
}

AActor::~AActor()
{
}


void AActor::BeginPlay()
{
}


void AActor::Tick()
{

}
void AActor::Render()
{
	GEngine->Render(X, Y, Mesh);
	GEngine->Render(X, Y, R, G, B);

}

void AActor::SetActorLocation(int InX, int InY)
{
	X = InX;
	Y = InY;
}
