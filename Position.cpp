#include "Position.h"

Position::Position()
{
	x = 0; y = 0;
}

Position::Position(int x, int y) : Position()
{
	set(x, y);
}

void Position::set(const Position& position)
{
	set(position.getX(), position.getY());
}

void Position::set(int x, int y)
{
	setX(x);
	setY(y);
}

int Position::getX() const
{
	return x;
}

int Position::getY() const
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
