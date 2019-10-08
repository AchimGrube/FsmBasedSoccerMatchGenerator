#include "PlayerStateDefend.h"
#include <iostream>

void PlayerStateDefend::doAction(Player& player, Pitch& pitch, Ball& ball)
{
	beginTurn(player, pitch);

	int rndPlayer = rand() % (10 / player.getLevel()) + 1;

	auto playerList = *pitch.getPlayersOnTiles(player.getPosition()->getX(), player.getPosition()->getY());

	for (auto opponent : playerList)
	{
		if (!opponent->hasBall() || player.getOpponentGoalPosition() == opponent->getOpponentGoalPosition())
		{
			continue;
		}

		std::cout << player.getName() << " geht in einen Zweikampf mit " << opponent->getName() << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));

		int rndOpponent = rand() % (opponent->getLevel()) + 1;

		if (rndPlayer >= rndOpponent)
		{
			std::cout << player.getName() << " gewinnt und startet einen Angriff.\n\n";

			player.hasBall(true);
			player.setState(State::Attack);
			player.setTarget(*player.getOpponentGoalPosition());

			opponent->hasBall(false);
			opponent->setState(State::Idle);
			opponent->setTarget(Position(0, 0));
		}
		else
		{
			std::cout << opponent->getName() << " gewinnt und bleibt am Ball.\n\n";

			player.hasBall(false);
			player.setState(State::Idle);
			player.setTarget(Position(0, 0));

			opponent->hasBall(true);
			opponent->setState(State::Attack);
			opponent->setTarget(*opponent->getOpponentGoalPosition());
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
	}

	player.setState(State::Move);
	player.setTarget(*ball.getPosition());

	endTurn(player, pitch);
}