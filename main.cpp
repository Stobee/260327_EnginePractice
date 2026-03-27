#include <iostream>
#include <fstream>

#include "Engine.h"
#include "World.h"

using namespace std;





int main()
{




	GEngine->GetInstance();
	GEngine->GetWorld()->LoadMap("TestMap.txt");
	GEngine->Run();
	
	delete GEngine;



	

	

	return 0;

}
