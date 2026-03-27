#pragma once

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
};

#define GEngine			UEngine::GetInstance()