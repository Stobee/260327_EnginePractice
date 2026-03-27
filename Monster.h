#pragma once
#include "Character.h"
class AMonster : public ACharacter
{
public:
	AMonster(int X = 0, int Y = 0, char Mesh = 'M', int HP = 10, int AP = 1);
	virtual ~AMonster();


	// 몬스터는 못 움직이게 함
	virtual void Tick() override; 
};

