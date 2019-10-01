#pragma once

#include "Player.h"
#include "Ball.h"

class IMatchEvents
{
public:

	virtual void playEvent(Player player, Player opponent, Ball ball) = 0;

private:

};