#pragma once

#include "Position.h"
#include "Direction.h"

class Entity abstract
{
public:

	Position* getPosition();
	void setPosition(const Position&);

	Direction* getDirection();
	void setDirection(const Direction&);

	virtual void move(Position&);

private:

	Position position;
	Direction direction;
};