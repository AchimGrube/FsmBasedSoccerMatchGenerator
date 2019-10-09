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

		string text = player.getName() + " dringt in den Strafraum ein und schiesst auf das Tor! (Chance: " + std::to_string(chance) + "%)\n";
		std::cout << text;
		Match::addTextOutput(text);
		std::this_thread::sleep_for(std::chrono::milliseconds(Match::textSpeed * 2));

		int rndGoalie = rand() % (10 / ((rand() % 5) + 1)) + 1;

		if (rndPlayer == 1)
		{
			if (rndPlayer <= rndGoalie)
			{
				text = "TOOOOR!!!\n\n";
				std::cout << text;
				Match::addTextOutput(text);
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
				text = "Der Torwart haelt den Ball.\n\n";
				std::cout << text;
				Match::addTextOutput(text);
			}
		}
		else
		{
			text = "Daneben!\n\n";
			std::cout << text;
			Match::addTextOutput(text);
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