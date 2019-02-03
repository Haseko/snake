#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

#include "World.h"

#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>

World::World(int w, int h, int l) {

	width = w;
	height = h;
	gameStatus = 1;
	latency = l;

	map.clear();

	for (int i = 0; i <= width+1; i++) {

		std::vector<int> row;
		row.clear();

		for (int j = 0; j <= height + 1; j++) {

			if (i == 0 || i == width + 1 || j == 0 || j == height+1) {

				row.push_back(1);

			}
			else {

				row.push_back(0);

			}

		}

		map.push_back(row);

	}

};

World::~World() {



};

void World::gameLoop() {

	drawWorld();
	userAction();
	makeStep();

	Sleep(latency);

};

bool World::gameProceeds() {

	return gameStatus;

};

void World::drawWorld() {

	system("cls");

	for (int i = 0; i < width+1; i++) {

		for (int j = 0; j < height+1; j++) {

			printf("%i",map[i][j]);

		}

		printf("\n");

	}

}

void World::userAction() {

	if (!kbhit()) {

		return;

	}

	int key;

	key = getch();

	switch(key) {

	case KEY_UP:
		dir = UP;
		break;
	case KEY_DOWN:
		dir = DOWN;
		break;
	case KEY_LEFT:
		dir = LEFT;
		break;
	case KEY_RIGHT:
		dir = RIGHT;
		break;

	}

}

void World::makeStep() {



}