#include "Entity.h"
#include "_functions.h"

std::unique_ptr<Position> Entity::getPosition()
{
	return std::make_unique<Position>(position);
}

void Entity::setPosition(const Position& position)
{
	this->position = position;
}

std::unique_ptr<Direction> Entity::getDirection()
{
	return std::make_unique<Direction>(direction);

}

void Entity::setDirection(const Direction& direction)
{
	this->direction = direction;
}

void Entity::move(Position& target)
{
	int stepX = Helper::sign(target.getX() - position.getX());
	int stepY = Helper::sign(target.getY() - position.getY());

	Position newPos = Position(position.getX() + stepX, position.getY() + stepY);
	setPosition(newPos);
}