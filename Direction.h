#pragma once

struct Direction
{
public:
	static const int NORTH = 0;
	static const int EAST = 1;
	static const int SOUTH = 2;
	static const int WEST = 3;

	Direction();

private:

	int directionX;
	int directionY;
	int stepsX;
	int stepsY;
};