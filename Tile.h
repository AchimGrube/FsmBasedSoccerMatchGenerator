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

	std::list<Player*> getPlayers();
	void addPlayer(Player*);
	void removePlayer(Player*);

	Area getArea();
	void setArea(Area);

private:

	int x, y;
	Area area;

	std::list<Player*> players;
};

