#include "PlayerStateIdle.h"

#include <iostream>

void PlayerStateIdle::doAction(Player& player, Ball& ball, Position& target)
{
	if (!player.hasBall())
	{
		player.setState(State::Move);
		player.setTarget(*ball.getPosition());
	}
}