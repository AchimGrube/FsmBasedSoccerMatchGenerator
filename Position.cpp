#include "Position.h"

Position::Position()
{
	x = 0; y = 0;
}

Position::Position(int x, int y) : Position()
{
	set(x, y);
}

void Position::set(int x, int y)
{
	setX(x);
	setY(y);
}

int Position::getX()
{
	return x;
}

int Position::getY()
{
	return y;
}

void Position::setX(int x)
{
	this->x = x;
}

void Position::setY(int y)
{
	this->y = y;
}
