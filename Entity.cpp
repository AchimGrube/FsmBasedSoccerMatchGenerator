#include "Entity.h"
#include "_functions.h"

Position* Entity::getPosition()
{
	return &position;
}

Direction* Entity::getDirection()
{
	return &direction;
}

void Entity::setDirection(const Direction& direction)
{
	this->direction = direction;
}

void Entity::move(Position& target)
{
	int stepX = Helper::sign(target.getX() - position.getX());
	int stepY = Helper::sign(target.getY() - position.getY());

	position.set(position.getX() + stepX, position.getY() + stepY);
}