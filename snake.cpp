#include <iostream>

#include "World.h"



int main()
{

	World game(30, 30, 500);

	while (game.gameProceeds()) {

		game.gameLoop();

	}

}