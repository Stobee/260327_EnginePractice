#pragma once

#include <Windows.h>
#include "SDL.h"

#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")

class UWorld;



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

	SDL_Window* MyWindow;
	SDL_Renderer* MyRenderer;
	SDL_Event MyEvent;

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

	static int KeyboardInput;

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

	// Renderer
	HANDLE ScreenBufferHandle[2];
	int ActiveScreenBufferIndex = 0;

	void InitBuffer();
	void Clear();
	void Render(int InX, int InY, char InMesh);
	void Render(int InX, int InY, int R, int G, int B);
	void Flip();
	void TermBuffer();
};

#define GEngine			UEngine::GetInstance()