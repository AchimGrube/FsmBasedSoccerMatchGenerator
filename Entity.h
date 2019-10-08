#pragma once

#include <memory>

#include "Position.h"

class Entity abstract
{
public:

	std::shared_ptr<Position> getPosition();
	void setPosition(const Position&);

	virtual void move(Position&);

private:

	Position position;
};