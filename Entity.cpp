#pragma once

#include "Entity.h"
#include "_functions.h"
#include "Position.h"

// Basisklasse für alles, was sich auf dem Spielfeld bewegen kann

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

// Bewegt Entität um 1 Feld horizontal, diagonal oder vertikal von seiner aktuellen Position in Richtung seiner Zielposition
void Entity::move(Position& target)
{
	int stepX = sign(target.getX() - position->getX());
	int stepY = sign(target.getY() - position->getY());

	setPosition(position->getX() + stepX, position->getY() + stepY);
}