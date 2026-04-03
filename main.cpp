#include <iostream>
#include <fstream>

#include "Engine.h"
#include "World.h"
#include "Component.h"

using namespace std;



int SDL_main(int argc, char* argv[])
{
	GEngine->GetWorld()->LoadMap("TestMap.txt");
	GEngine->Run();

	delete GEngine;
	
	

	return 0;
}

