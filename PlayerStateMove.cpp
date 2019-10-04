#include "PlayerStateMove.h"
#include <iostream>

void PlayerStateMove::doAction(Player& player, Pitch& pitch, Ball& ball, Position& target)
{
	//beginTurn(player, pitch);
	player.setTarget(*ball.getPosition());
	player.move(*player.getTarget());
	//endTurn(player, pitch);
	
	auto currentTile = 	pitch.getTile(player.getPosition()->getX(), player.getPosition()->getY());
	auto playersOnTile = currentTile->getPlayers();

	auto TESTptrAddress = &*currentTile;

	playersOnTile.push_back(std::make_shared<Player>(player));

	if (player.getPosition()->getX() == ball.getPosition()->getX() && player.getPosition()->getY() == ball.getPosition()->getY())
	{
		if (playersOnTile.size() > 1)
		{
			std::cout << "\nGegner auf dem Feld!\n\n";
		}
		else
		{
			player.hasBall(true);
			player.setState(State::Attack);
		}
	}
}