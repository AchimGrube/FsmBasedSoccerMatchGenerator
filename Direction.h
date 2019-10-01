#pragma once

struct Direction
{
public:
	static const int LEFT = -1;
	static const int RIGHT = 1;
	static const int UP = -1;
	static const int DOWN = 1;

	Direction();

	int getHorizontal();
	void setHorizontal(int);

	int getVertical();
	void setVertical(int);

private:

	int horizontal;
	int vertical;
};