#pragma once

#include "Position.h"
#include "Direction.h"

class Entity abstract
{
public:

	Position* getPosition();

	Direction* getDirection();
	void setDirection(Direction*);

	virtual void move(Position& const);

private:

	Position* position;
	Direction* direction;
};