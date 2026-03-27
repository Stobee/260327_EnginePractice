#include "Actor.h"

#include <Windows.h>
#include <iostream>

AActor::AActor(int InX, int InY, char InMesh) : X(InX), Y(InY), Mesh(InMesh)
{
	
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
	COORD Coordinate;
	Coordinate.X = X;
	Coordinate.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coordinate);

	std::cout << Mesh;

}

void AActor::SetActorLocation(int InX, int InY)
{
	X = InX;
	Y = InY;
}
