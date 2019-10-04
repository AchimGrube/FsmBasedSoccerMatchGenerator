#pragma once

#include <memory>
#include <array>

#include "Tile.h"

class Pitch
{
public:

	static const int sizeX = 17;
	static const int sizeY = 11;

	Pitch();

	std::shared_ptr<Tile> getTile(int, int);

private:

	std::array<std::array<Tile, sizeY>, sizeX> tiles;
};

