#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

#include "World.h"

#include "Snake.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
//#include <random>
//
//std::default_random_engine generator;
//std::uniform_int_distribution<int> distribution(1, 6);

BOOL ShowConsoleCursor(BOOL bShow)
{
	CONSOLE_CURSOR_INFO cci;
	HANDLE hStdOut;
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE)
		return FALSE;
	if (!GetConsoleCursorInfo(hStdOut, &cci))
		return FALSE;
	cci.bVisible = bShow;
	if (!SetConsoleCursorInfo(hStdOut, &cci))
		return FALSE;
	return TRUE;
}


World::World(int h, int w, int l) {

	ShowConsoleCursor(FALSE);

	width = w;
	height = h;
	gameStatus = 1;
	latency = l;
	snake = Snake((int) w/2, (int) h/2);
	//fruitX = distribution(generator);

	map.clear();

	for (int i = 0; i <= height +1; i++) {

		std::vector<int> row;
		row.clear();

		for (int j = 0; j <= width + 1; j++) {

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
	time++;

	if (latency*time > 10000) {

		time = 0;
		makeFruit();

	}

	Sleep(latency);

};

void World::makeFruit() {
	
	tailxy fruit;
	int k = 1;

	while (k) {

		fruit.x = (rand() - 1) % width + 1;
		fruit.y = (rand() - 1) % height + 1;

		k = 0;

		for (auto i = fruits.begin(); i != fruits.end(); i++) {

			if (fruit.x == (i->second).x && fruit.y == (i->second).y) {

				k = 1;

			}

		}

		std::vector <tailxy> tail;

		tail = snake.getTail();

		for (tailxy i: tail) {

			if (fruit.x == i.x && fruit.y == i.y) {

				k = 1;

			}

		}

	}

	fruits.insert(std::make_pair(0, fruit));

}

int World::getWidth() {

	return width;

};

int World::getHeight() {

	return height;

};

bool World::gameProceeds() {

	return gameStatus;

};

void World::drawWorld() {

	system("cls");

	for (int i = 0; i <= height + 1; i++) {

		for (int j = 0; j <= width + 1; j++) {

			switch (map[i][j]) {

			case 0:
				printf(" ");
				break;
			case 1:
				printf("#");
				break;
			case 2:
				printf("*");
				break;
			case 3:
				printf("~");
				break;

			};

		}

		printf("\n");

	}

	int scoreNow = snake.getScore();
	int sizeNow = snake.getSize();

	std::cout << "Score: " << scoreNow << std::endl;

}

void World::userAction() {

	if (!_kbhit()) {

		return;

	}

	int key;

	key = _getch();

	switch(key) {

	case KEY_UP:
		snake.setDir(0);
		break;
	case KEY_DOWN:
		snake.setDir(1);
		break;
	case KEY_LEFT:
		snake.setDir(2);
		break;
	case KEY_RIGHT:
		snake.setDir(3);
		break;

	}

}

void World::makeStep() {

	snake.move(height, width);

	for (int i = 1; i <= height; i++) {

		for (int j = 1; j <= width; j++) {

			map[i][j] = 0;

		}

	}

	std::vector<tailxy> tail;

	tail = snake.getTail();

	tailxy pos;
	int length = snake.getSize();

	pos = snake.getPos();

	for (int i = 0; i < length; i++) {

		map[tail[i].x][tail[i].y] = 3;
		if (tail[i].x == pos.x && tail[i].y == pos.y) {

			gameStatus = 0;

		}

	}

	for (auto i = fruits.begin(); i != fruits.end(); i++) {

		if (pos.x == (i->second).x && pos.y == (i->second).y) {

			snake.eatFood();
			fruits.erase(i);
			break;


		}

	}

	for (auto i = fruits.begin(); i != fruits.end(); i++) {

		map[i->second.x][i->second.y] = 2;

	}

	map[pos.x][pos.y] = 3;

}