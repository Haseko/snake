#include "Snake.h"

Snake::Snake(int x, int y) {

	pos.x = x;
	pos.y = y;
	score = 0;
	length = 0;
	dir = LEFT;

	tail.clear();

};

Snake::Snake() {

	pos.x = 0;
	pos.y = 0;
	score = 0;
	dir = LEFT;

	tail.clear();

	tailxy p;
	p.x = 1;
	p.y = 0;
	tail.push_back(p);
	p.x = 2;
	p.y = 0;
	tail.push_back(p);
	p.x = 3;
	p.y = 0;
	tail.push_back(p);

	length = 3;

};

Snake::~Snake() {



};

void Snake::eatFood() {

	length++;
	score++;
	
	tail.push_back(pos);

}

void Snake::move(int height, int width) {

	for (int i = length-1; i >= 1; i--) {

		tail[i] = tail[i - 1];

	};

	if (length > 0) {

		tail[0] = pos;

	};
		
	switch (dir) {

	case UP:
		pos.x--;
		break;
	case DOWN:
		pos.x++;
		break;
	case LEFT:
		pos.y--;
		break;
	case RIGHT:
		pos.y++;
		break;

	}

	if (pos.x > width) {

		pos.x = 1;

	} else
	if (pos.x < 1) {

		pos.x = width;

	}

	if (pos.y > height) {

		pos.y = 1;

	}
	else
	if (pos.y < 1) {

		pos.y = height;

	}

}

std::vector<tailxy> Snake::getTail() {

	return tail;

};

tailxy Snake::getPos() {

	return pos;

};

int Snake::getSize() {

	return length;

};

int Snake::getScore() {

	return score;

};

void Snake::setDir(int direct) {

	switch (direct) {

	case 0:
		dir = UP;
		break;
	case 1:
		dir = DOWN;
		break;
	case 2:
		dir = LEFT;
		break;
	case 3:
		dir = RIGHT;
		break;

	}

}