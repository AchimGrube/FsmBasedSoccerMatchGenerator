#pragma once

#include <list>

class Player;

enum class Area
{
	Out, Goal, Penalty, Center, Wing
};

class Tile
{
public:

	Tile(int, int, Area);
	~Tile();

	int getX() const;
	int getY() const;

	Area getArea() const;
	void setArea(const Area&);

	std::list<Player*>* getPlayers();
	void addPlayer(Player&);
	void removePlayer(const Player&);

private:

	int x;
	int y;
	Area area;

	std::list<Player*> players;
};