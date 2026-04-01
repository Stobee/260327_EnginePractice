#include <iostream>
#include <fstream>

#include "Engine.h"
#include "World.h"

#include <random>
#include <cmath>


using namespace std;



int SDL_main(int argc, char* argv[])
{
	
	GEngine->GetInstance();
	GEngine->GetWorld()->LoadMap("TestMap.txt");
	GEngine->Run();

	delete GEngine;
	
	

	return 0;
}

