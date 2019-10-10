#pragma once

#include <array>
#include <memory>

#include "Tile.h"

class Pitch
{
public:

	static const int SIZE_X = 17;
	static const int SIZE_Y = 11;

	Pitch();
	~Pitch();

	std::shared_ptr<Tile> getTile(int, int);

private:

	std::array<std::array<std::shared_ptr<Tile>, SIZE_Y>, SIZE_X> tiles;
};