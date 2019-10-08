#include "PlayerStateAttack.h"
#include <iostream>
#include "Match.h"

void PlayerStateAttack::doAction(Player& player, Pitch& pitch, Ball& ball)
{
	beginTurn(player, pitch);

	player.setTarget(*player.getOpponentGoalPosition());
	player.move(*player.getTarget());
	ball.move(*player.getPosition());

	if (pitch.getTile(player.getPosition()->getX(), player.getPosition()->getY())->getArea() == Area::Penalty && player.hasBall())
	{
		int rndPlayer = rand() % (10 / player.getLevel()) + 1;

		int chance = 10 * player.getLevel();

		std::cout << player.getName() << " dringt in den Strafraum ein und schiesst auf das Tor! (Chance: " << chance << "%)" << std::endl;

		int rndGoalie = rand() % 2;

		if (rndPlayer == 1)
		{
			if (rndGoalie == 0)
			{
				std::cout << "TOOOOR!!!" << std::endl;
				if (player.getOpponentGoalPosition()->getX() > 8)
				{
					Match::addGoalTeamA();
				}
				else
				{
					Match::addGoalTeamB();
				}
			}
			else
			{
				std::cout << "Der Torwart haelt den Ball." << std::endl;
			}
		}
		else
		{
			std::cout << "Daneben!" << std::endl;
		}

		player.hasBall(false);
		player.setState(State::Idle);
		player.setTarget(*ball.getPosition());

		ball.setPosition(Position(8, 5));
	}

	endTurn(player, pitch);
}