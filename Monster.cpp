#include "Monster.h"

AMonster::AMonster(int InX, int InY, char InMesh, int InHP, int InAP)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	HP = InHP;
	AP = InAP;
	ZOrder = 50;
}

AMonster::~AMonster()
{
}

void AMonster::Tick()
{
}
