#include "PlayerStateAttack.h"
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
		std::this_thread::sleep_for(std::chrono::milliseconds(Match::textSpeed * 2));

		int rndGoalie = rand() % (10 / ((rand() % 5) + 1)) + 1;

		if (rndPlayer == 1)
		{
			if (rndPlayer <= rndGoalie)
			{
				std::cout << "TOOOOR!!!\n\n";
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
				std::cout << "Der Torwart haelt den Ball.\n\n";
			}
		}
		else
		{
			std::cout << "Daneben!\n\n";
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(Match::textSpeed));

		player.hasBall(false);
		player.setState(State::Idle);
		player.setTarget(Position(0, 0));

		ball.setPosition(Position(8, 5));

		for (int x = 0; x < Pitch::sizeX; x++)
		{
			for (int y = 0; y < Pitch::sizeY; y++)
			{
				auto playerList = *pitch.getPlayersOnTiles(x, y);

				for (auto element : playerList)
				{
					element->hasBall(false);
					element->setState(State::Idle);
					element->setTarget(Position(0, 0));
				}
			}
		}
	}

	endTurn(player, pitch);
}