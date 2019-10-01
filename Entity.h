#pragma once

#include "Position.h"
#include "Direction.h"

class Entity abstract
{
public:

	Position* getPosition();

	Direction* getDirection();
	void setDirection(const Direction&);

	virtual void move(Position&);

private:

	Position position;
	Direction direction;
};