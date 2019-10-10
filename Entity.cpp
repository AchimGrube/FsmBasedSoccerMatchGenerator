#pragma once

#include "Entity.h"
#include "_functions.h"
#include "Position.h"

Entity::Entity()
{
	this->position = std::make_shared<Position>();
}

std::shared_ptr<Position> Entity::getPosition()
{
	return std::shared_ptr<Position>(this->position);
}

void Entity::setPosition(int x, int y)
{
	this->position->set(x, y);
}

void Entity::move(Position& target)
{
	int stepX = sign(target.getX() - position->getX());
	int stepY = sign(target.getY() - position->getY());

	setPosition(position->getX() + stepX, position->getY() + stepY);
}