#include "Entity.h"
#include "_functions.h"

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

void Entity::move(int x, int y)
{
	int stepX = Helper::sign(x);
	int stepY = Helper::sign(y);

	position->setX(x);
	position->setY(y);
}