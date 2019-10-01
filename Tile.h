#pragma once

enum class Area
{
	Out, Goal, Penalty, Center, Wing
};

class Tile
{
public:

	Tile(int, int);
	
	int getX();
	int getY();

	Area getArea();
	void setArea(Area);

private:

	int x, y;
	Area area;
};

