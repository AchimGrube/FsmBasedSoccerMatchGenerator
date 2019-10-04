#pragma once

#include <memory>

#include "Position.h"
#include "Direction.h"

class Entity abstract
{
public:

	std::shared_ptr<Position> getPosition();
	void setPosition(const Position&);

	std::shared_ptr<Direction> getDirection();
	void setDirection(const Direction&);

	virtual void move(Position&);

private:

	Position position;
	Direction direction;
};