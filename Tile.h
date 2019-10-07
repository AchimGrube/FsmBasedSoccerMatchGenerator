#pragma once

#include <list>

#include "Player.h"

enum class Area
{
	Out, Goal, Penalty, Center, Wing
};

class Tile
{
public:

	Tile();
	Tile(int, int);
	
	int getX() const;
	int getY() const;

	Area getArea();
	void setArea(Area);

private:

	int x, y;
	Area area;
};

