#pragma once

#include "Player.h"
#include "Ball.h"
#include "Position.h"

class IPlayerState
{
public:

	virtual void doAction(Player player, Ball ball, Position target) = 0;

private:

};