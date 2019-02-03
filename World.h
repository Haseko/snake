#pragma once

#include <vector>

class World {

public:
	World(int w, int h, int l);
	~World();

	bool gameProceeds();
	void gameLoop();

private:

	int width;
	int height;
	int latency;
	bool gameStatus;
	enum { UP = 0, DOWN, LEFT, RIGHT } dir;

	std::vector<std::vector<int>> map;

	void drawWorld();
	void userAction();
	void makeStep();

};