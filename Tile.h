#pragma once

enum class Area
{
	Out, Goal, Penalty, Center, Wing
};

class Tile
{
public:

	int getX();
	int getY();

private:

	int x, y;
	Area area;
};

