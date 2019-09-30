#pragma once

struct Direction
{
public:
	static const int UP = -1;
	static const int DOWN = 1;
	static const int LEFT = -1;
	static const int RIGHT = 1;

	Direction();

private:

	int directionX;
	int directionY;
};