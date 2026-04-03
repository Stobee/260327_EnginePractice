#pragma once
#include "Actor.h"
class ACharacter :public AActor
{public:
	ACharacter();
	virtual ~ACharacter();

protected:
	bool PredictMove(int InX, int InY); // movement 컴포넌트가 되어야 함
};

