#pragma once

#include "Player.h"
#include "Ball.h"
#include "Position.h"

class IPlayerState
{
public:

	virtual void doAction(Player&, Ball&, Position&) = 0;

private:

};