#include <iostream>
#include <windows.h>

#include "Command/GameActor.cpp"
#include "Command/InputHandler.cpp"

using namespace std;

int main() 
{
    GameActor actor;
    InputHandler inputhandler;

    cout << " Press Any Key:" << endl;
    while(true) {
		SHORT keyState = GetKeyState(VK_SPACE);
		if(keyState & 0x8000) {
			std::cout << "Space key is pressed." << std::endl;
		}
	}
    
	return 0;
}