#include "PlayerStateMove.h"

void PlayerStateMove::doAction(Player& player, Ball& ball, Position& target)
{
	player.setTarget(*ball.getPosition());
	player.move(*player.getTarget());

	if (player.getPosition()->getX() == ball.getPosition()->getX() && player.getPosition()->getY() == ball.getPosition()->getY())
	{
		player.setState(State::Idle);
		player.hasBall(true);
	}
}