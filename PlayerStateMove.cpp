#include "PlayerStateMove.h"
#include <iostream>

void PlayerStateMove::doAction(Player& player, Pitch& pitch, Ball& ball, Position& target)
{
	beginTurn(player, pitch);
	player.setTarget(*ball.getPosition());
	player.move(*player.getTarget());
	endTurn(player, pitch);
	
	//pitch.addPlayerOnTile(player, player.getPosition()->getX(), player.getPosition()->getY());

	if (player.getPosition()->getX() == ball.getPosition()->getX() && player.getPosition()->getY() == ball.getPosition()->getY())
	{
		if (pitch.getPlayersOnTiles(player.getPosition()->getX(), player.getPosition()->getY())->size() > 1)
		{
			player.setState(State::Defend);
		}
		else
		{
			player.hasBall(true);
			player.setState(State::Attack);
		}
	}
}