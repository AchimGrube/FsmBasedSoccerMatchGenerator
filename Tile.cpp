#include "Tile.h"

Tile::Tile(int x, int y)
{
	this->x = x;
	this->y = y;
	area = Area::Out;
}

int Tile::getX()
{
	return x;
}

int Tile::getY()
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