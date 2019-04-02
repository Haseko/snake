#pragma once

#include <vector>
#include <map>
#include "Snake.h"

class World {

public:
	World(int w, int h, int l);
	~World();

	bool gameProceeds();
	void gameLoop();
	void makeFruit();
	int getWidth();
	int getHeight();

private:

	int width;
	int height;
	int latency;
	int points;
	int time;
	bool gameStatus;
	Snake snake;
	
	std::multimap<int, tailxy> fruits;
	std::vector<std::vector<int>> map;

	void drawWorld();
	void userAction();
	void makeStep();

};