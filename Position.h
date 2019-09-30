#pragma once

struct Position
{
public:

	Position();
	Position(int x, int y);

	int getX();
	void setX(int x);

	int getY();
	void setY(int y);

private:
	int x = 0, y = 0;
};