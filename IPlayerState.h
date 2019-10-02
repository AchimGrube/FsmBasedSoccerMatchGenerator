#pragma once

#include <string>

#include "Ball.h"
#include "Position.h"

class Player;

class IPlayerState abstract
{
public:

	virtual void doAction(Player&, Ball&, Position&) = 0;

private:

};