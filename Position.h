#pragma once

struct Position
{
public:

	Position();
	Position(int, int);
	~Position();

	void set(Position&);
	void set(int, int);

	int getX();
	int getY();

private:

	int x;
	int y;

	void setX(int);
	void setY(int);
};