#pragma once
#include "Character.h"
class APlayer : public ACharacter
{public: 
	APlayer(int X = 0, int Y = 0, char Mesh = 'P', int HP = 100, int AP = 5);
	virtual ~APlayer();
};

