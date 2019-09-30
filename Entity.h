#pragma once

#include "Position.h"
#include "Direction.h"

class Entity abstract
{
public:

	Entity();

	int getPositionX();
	void setPositionX(int);

	int getPositionY();
	void setPositionY(int);

	virtual void move(int, int);

private:

	Position* position;
	Direction* direction;
};