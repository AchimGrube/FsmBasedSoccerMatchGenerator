#pragma once

#include <memory>

#include "Position.h"
#include "Direction.h"

class Entity abstract
{
public:

	std::unique_ptr<Position> getPosition();
	void setPosition(const Position&);

	std::unique_ptr<Direction> getDirection();
	void setDirection(const Direction&);

	virtual void move(Position&);

private:

	Position position;
	Direction direction;
};