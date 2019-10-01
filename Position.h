#pragma once

struct Position
{
public:

	Position();
	Position(int x, int y);

	void set(int, int);

	int getX() const;
	int getY() const;

private:
	int x = 0, y = 0;

	void setX(int);
	void setY(int);
};