#include "PlayerStateIdle.h"

void PlayerStateIdle::doAction(Player& player, Pitch& pitch, Ball& ball)
{
	beginTurn(player, pitch);

	if (!player.hasBall())
	{
		player.hasBall(false);
		player.setState(State::Move);
		player.setTarget(*ball.getPosition());
	}

	endTurn(player, pitch);
}