#include "PlayerStateIdle.h"

#include <iostream>

void PlayerStateIdle::doAction(Player& player, Pitch& pitch, Ball& ball)
{
	if (!player.hasBall())
	{
		player.setState(State::Move);
		player.setTarget(*ball.getPosition());
	}
}