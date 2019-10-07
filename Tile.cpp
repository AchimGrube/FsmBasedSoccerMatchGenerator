#include "Tile.h"

Tile::Tile()
{
	x = y = 0;
	area = Area::Out;
}

Tile::Tile(int x, int y) : Tile()
{
	this->x = x;
	this->y = y;
}

int Tile::getX() const
{
	return x;
}

int Tile::getY() const
{
	return y;
}

Area Tile::getArea()
{
	return area;
}

void Tile::setArea(Area area)
{
	this->area = area;
}