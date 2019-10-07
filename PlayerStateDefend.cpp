#include "PlayerStateDefend.h"
#include <iostream>

void PlayerStateDefend::doAction(Player& player, Pitch& pitch, Ball& ball)
{
	beginTurn(player, pitch);

	int rndPlayer = rand() % (10 / player.getLevel()) + 1;

	std::list<std::shared_ptr<Player>> playerList;
	playerList = std::list<std::shared_ptr<Player>>(*pitch.getPlayersOnTiles(player.getPosition()->getX(), player.getPosition()->getY()));

	for (std::shared_ptr<Player> opponent : playerList)
	{
		std::cout << player.getName() << " geht in einen Zweikampf mit " << opponent->getName() << std::endl;
		
		int rndOpponent = rand() % (opponent->getLevel()) + 1;

		if (rndPlayer >= rndOpponent)
		{
			std::cout << player.getName() << " gewinnt und startet einen Angriff." << std::endl;
			
			player.hasBall(true);
			player.setState(State::Attack);

			opponent->hasBall(false);
			opponent->setState(State::Idle);
		}
		else
		{
			std::cout << opponent->getName() << " gewinnt und bleibt am Ball." << std::endl;
			
			player.hasBall(false);
			player.setState(State::Idle);

			opponent->hasBall(true);
			opponent->setState(State::Attack);
		}

	}
}