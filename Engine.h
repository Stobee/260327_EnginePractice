#pragma once

#include <Windows.h>
#include "SDL.h"

#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")

class UWorld;
class UResourceManager;


class UEngine
{
protected:
	UEngine();
	static UEngine* Instance;

	void Input();
	void Tick();
	void Render();

	UWorld* World;
	bool bIsRunning : 1;

	float DeltaSeconds;

	SDL_Window* MyWindow;
	SDL_Renderer* MyRenderer;
	SDL_Event MyEvent;

	UResourceManager* ResourceManager;

public:
	
	~UEngine();

	static UEngine* GetInstance()
	{
		if (Instance == nullptr)
		{
			Instance = new UEngine;
		}
		return Instance;
	}


	inline UWorld* GetWorld()
	{
		return World;
	}
	void Init();
	void Term();
	void Run();
	void Stop();

	inline const SDL_Event& GetEvent()
	{
		return MyEvent;
	}

	inline float GetDeltaSeconds()const
	{
		return DeltaSeconds;
	}
	inline SDL_Renderer* GetRenderer()const
	{
		return MyRenderer;
	}
	inline SDL_Window* GetWindow() const
	{
		return MyWindow;
	}
	inline UResourceManager* GetResourceManager() const
	{
		return ResourceManager;
	}
	// Renderer
	HANDLE ScreenBufferHandle[2];
	int ActiveScreenBufferIndex = 0;

	void InitBuffer();
	void Clear();
	void Render(int InX, int InY, char InMesh);
	void Render(int InX, int InY, int R, int G, int B);
	void Render(int InX, int InY, SDL_Texture* InTexture);
	void Flip();
	void TermBuffer();
};

#define GEngine			UEngine::GetInstance()