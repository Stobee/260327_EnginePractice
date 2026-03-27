#pragma once
class AActor
{public: 
	AActor(int InX = 0, int InY = 0, char InMesh = ' ');
	virtual ~AActor();

	virtual void BeginPlay();
	virtual void Tick();
	virtual void Render();

	void SetActorLocation(int InX, int InY);

	int GetZOrder()
	{
		return ZOrder;
	}

protected:
	int X;
	int Y;
	char Mesh;
	int ZOrder = 0;

};

