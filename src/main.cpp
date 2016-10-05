#include <SDL2/SDL.h>

#include <iostream>
#include "SpaceIntruders.hpp"

int main()
{
	SpaceIntruders spaceIntruders;
	if(spaceIntruders.start() != 0){
		return -1;
	}

    return 0;
}
