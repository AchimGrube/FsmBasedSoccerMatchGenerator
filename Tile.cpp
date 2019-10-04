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

std::list<std::shared_ptr<Player>> Tile::getPlayers()
{
	return players;
}

void Tile::addPlayer(Player& player)
{
	players.push_back(std::make_shared<Player>(player));
}

void Tile::removePlayer(Player& player)
{
	std::shared_ptr<Player> remove = nullptr;

	for (auto element : players)
	{
		if (element == std::make_shared<Player>(player))
		{
			remove = element;
		}
	}

	if (remove != nullptr)
	{
		players.remove(remove);
	}
}

Area Tile::getArea()
{
	return area;
}

void Tile::setArea(Area area)
{
	this->area = area;
}