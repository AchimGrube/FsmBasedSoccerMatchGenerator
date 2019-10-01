#pragma once

#include "Tile.h"

class Pitch
{
public:

	static const int sizeX = 17;
	static const int sizeY = 11;

	Pitch();

	Tile* getTile(int, int);

private:

	Tile* tiles[sizeX][sizeY];
};

