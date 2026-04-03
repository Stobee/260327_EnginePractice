#pragma once

// 추상클래스
class UComponent
{public:
	UComponent();
	virtual ~UComponent();

	virtual void BeginPlay() = 0;
	virtual void Tick() = 0;

	class AActor* Owner;
};

