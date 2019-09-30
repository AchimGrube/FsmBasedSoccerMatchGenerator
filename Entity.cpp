#include "Entity.h"

Entity::Entity()
{
	position = new Position();
	direction = new Direction();
}

int Entity::getPositionX()
{
	return position->getX();
}

void Entity::setPositionX(int x)
{
	position->setX(x);
}

int Entity::getPositionY()
{
	return position->getY();
}

void Entity::setPositionY(int y)
{
	position->setY(y);
}

void Entity::moveTo(int x, int y)
{
	position->setX(x);
	position->setY(y);
}