#pragma once

#include <vector>

struct tailxy {

	int x;
	int y;

};

class Snake {

public:

	Snake(int x, int y);
	Snake();
	~Snake();
	
	void eatFood();
	void move(int height, int width);

	std::vector<tailxy> getTail();
	tailxy getPos();
	int getSize();
	int getScore();

	void setDir(int direct);

private:

	int length;
	int score;


	tailxy pos;

	enum { UP = 0, DOWN, LEFT, RIGHT } dir;
	std::vector <tailxy> tail;

};