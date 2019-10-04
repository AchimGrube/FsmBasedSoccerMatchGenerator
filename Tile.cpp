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

std::list<Player*> Tile::getPlayers()
{
	return players;
}

void Tile::addPlayer(Player* player)
{
	players.push_back(player);
}

void Tile::removePlayer(Player* player)
{
	Player* remove = nullptr;

	for (auto element : players)
	{
		if (element == player)
		{
			remove = element;
		}
	}

	if (remove != nullptr)
	{
		players.remove(remove);
	}

	delete remove;
}

Area Tile::getArea()
{
	return area;
}

void Tile::setArea(Area area)
{
	this->area = area;
}