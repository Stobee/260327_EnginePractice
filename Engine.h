#pragma once

#include <Windows.h>

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

	// Renderer
	HANDLE ScreenBufferHandle[2];
	int ActiveScreenBufferIndex = 0;

	void InitBuffer();
	void Clear();
	void Render(int InX, int InY, char InMesh);
	void Flip();
	void TermBuffer();
};

#define GEngine			UEngine::GetInstance()