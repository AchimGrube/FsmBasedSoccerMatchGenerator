#pragma once

#include <memory>
#include <array>
#include <list>

#include "Tile.h"

class Pitch
{
public:

	static const int sizeX = 17;
	static const int sizeY = 11;

	Pitch();

	std::shared_ptr<Tile> getTile(int, int);

	std::shared_ptr<std::list<std::shared_ptr<Player>>> getPlayersOnTiles(int, int);
	void addPlayerOnTile(Player&, int, int);
	void removePlayerOnTile(Player&, int, int);

private:

	std::array<std::array<Tile, sizeY>, sizeX> tiles;
	std::array<std::array<std::list<std::shared_ptr<Player>>, sizeY>, sizeX> playersOnTiles;
};

