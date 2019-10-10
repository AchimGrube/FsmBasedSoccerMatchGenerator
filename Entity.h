#pragma once

#include <memory>

struct Position;

class Entity abstract
{
public:

	Entity();

	std::shared_ptr<Position> getPosition();
	void setPosition(int, int);

	virtual void move(Position&);

private:

	std::shared_ptr<Position> position;
};