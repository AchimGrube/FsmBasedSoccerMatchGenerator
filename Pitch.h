#pragma once

#include <memory>

#include "Tile.h"

class Pitch
{
public:

	static const int sizeX = 17;
	static const int sizeY = 11;

	Pitch();

	std::unique_ptr<Tile> getTile(int, int);

private:

	Tile tiles[sizeX][sizeY];
};

