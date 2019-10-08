#include "Entity.h"
#include "_functions.h"

std::shared_ptr<Position> Entity::getPosition()
{
	return std::make_shared<Position>(position);
}

void Entity::setPosition(const Position& position)
{
	this->position = position;
}

void Entity::move(Position& target)
{
	int stepX = Helper::sign(target.getX() - position.getX());
	int stepY = Helper::sign(target.getY() - position.getY());

	Position newPos = Position(position.getX() + stepX, position.getY() + stepY);
	setPosition(newPos);
}