#include "Direction.h"

Direction::Direction()
{
	horizontal = Direction::RIGHT;
	vertical = Direction::DOWN;
}

int Direction::getHorizontal() const
{
	return horizontal;
}

void Direction::setHorizontal(int horizontal)
{
	this->horizontal = horizontal;
}

int Direction::getVertical() const
{
	return vertical;
}

void Direction::setVertical(int vertical)
{
	this->vertical = vertical;
}