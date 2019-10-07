#include "PlayerStateMove.h"
#include <iostream>

void PlayerStateMove::doAction(Player& player, Pitch& pitch, Ball& ball)
{
	beginTurn(player, pitch);

	player.setTarget(*ball.getPosition());
	player.move(*player.getTarget());
	
	if (player.getPosition()->getX() == ball.getPosition()->getX() && player.getPosition()->getY() == ball.getPosition()->getY())
	{
		if (pitch.getPlayersOnTiles(player.getPosition()->getX(), player.getPosition()->getY())->size() > 0)
		{
			player.setState(State::Defend);
			player.hasBall(false);
			player.setTarget(*ball.getPosition());
		}
		else
		{
			std::cout << player.getName() << " schnappt sich den Ball und startet einen Angriff." << std::endl;

			player.hasBall(true);
			player.setState(State::Attack);
			player.setTarget(*player.getOpponentGoalPosition());
		}
	}

	endTurn(player, pitch);
}