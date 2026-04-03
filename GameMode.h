#pragma once
#include "Actor.h"

class AGameMode : public AActor
{public:
	AGameMode();
	virtual ~AGameMode();

	virtual void Tick() override; // 틱 적용은 좋은 방식은 아님

	void GameOver();
	void GameComplete();
};

