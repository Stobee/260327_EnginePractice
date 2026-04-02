#pragma once

#include <string>

struct SDL_Surface;
struct SDL_Texture;



class AActor
{public: 
	AActor(int InX = 0, int InY = 0, char InMesh = ' ');
	virtual ~AActor();

	virtual void BeginPlay();
	virtual void Tick();
	virtual void Render();

	void SetActorLocation(int InX, int InY);

	
	
	inline const int GetZOrder() const
	{
		return ZOrder;
	}

protected:
	int X;
	int Y;

	int R;
	int G;
	int B;

	char Mesh;
	int ZOrder = 0;

	SDL_Surface* Image;
	SDL_Texture* Texture;

};

