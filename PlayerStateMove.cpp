#include "PlayerStateMove.h"

void PlayerStateMove::doAction(Player& player, Ball& ball, Position& target)
{
	player.setTarget(*ball.getPosition());
	player.move(*player.getTarget());
}