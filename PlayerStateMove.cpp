#include "PlayerStateMove.h"
#include <iostream>

void PlayerStateMove::doAction(Player& player, Pitch& pitch, Ball& ball, Position& target)
{
	player.setTarget(*ball.getPosition());
	player.move(*player.getTarget());

	if (player.getPosition()->getX() == ball.getPosition()->getX() && player.getPosition()->getY() == ball.getPosition()->getY())
	{
		int size = pitch.getTile(player.getPosition()->getX(), player.getPosition()->getY())->getPlayers().size();

		//if (size.size() > 0)
		//{
		//	std::cout << "Gegner auf dem Feld!" << std::endl;;
		//}

		//player.setState(State::Idle);
		//player.hasBall(true);
	}
}