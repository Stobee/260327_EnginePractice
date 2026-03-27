#include "Player.h"

APlayer::APlayer(int InX, int InY, char InMesh, int InHP, int InAP)
{
	X = InX;
	Y = InY;
	Mesh = InMesh;
	HP = InHP;
	AP = InAP;
	ZOrder = 100;
	
}

APlayer::~APlayer()
{
}
