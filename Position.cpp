#pragma once

#include "Position.h"

// Einfache Struktur zur Verwaltung der Position im zweidimensional Array

Position::Position()
{
	x = 0;
	y = 0;
}

Position::Position(int x, int y) : Position()
{
	set(x, y);
}

Position::~Position()
{
}

void Position::set(Position& position)
{
	set(position.getX(), position.getY());
}

void Position::set(int x, int y)
{
	setX(x);
	setY(y);
}

int Position::getX()
{
	return this->x;
}

int Position::getY()
{
	return this->y;
}

void Position::setX(int x)
{
	this->x = x;
}

void Position::setY(int y)
{
	this->y = y;
}