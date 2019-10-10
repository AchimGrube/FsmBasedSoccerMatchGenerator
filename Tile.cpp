#pragma once

#include "Tile.h"

Tile::Tile(int x, int y, Area area)
{
	this->x = x;
	this->y = y;
	this->area = area;
}

Tile::~Tile()
{
}

int Tile::getX() const
{
	return this->x;
}

int Tile::getY() const
{
	return this->y;
}

Area Tile::getArea() const
{
	return this->area;
}

void Tile::setArea(const Area& area)
{
	this->area = area;
}

std::list<Player*>* Tile::getPlayers()
{
	return &players;
}

void Tile::addPlayer(Player& player)
{
	players.push_back(&player);
}

void Tile::removePlayer(const Player& player)
{
	Player* remove = nullptr;

	for (auto element : players)
	{
		if (element == &player)
		{
			remove = element;
			break;
		}
	}

	if (remove != nullptr)
	{
		players.remove(remove);
	}
}