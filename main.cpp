#include <iostream>

#include "World.h"
#include "Snake.h"



int main()
{

	World game(20, 20, 200);

	while (game.gameProceeds()) {

		game.gameLoop();

	}

}