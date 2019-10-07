#include "PlayerStateAttack.h"
#include <iostream>

void PlayerStateAttack::doAction(Player& player, Pitch& pitch, Ball& ball)
{
	beginTurn(player, pitch);

	player.move(*player.getTarget());
	ball.move(*player.getPosition());

	auto test = pitch.getTile(player.getPosition()->getX(), player.getPosition()->getY())->getArea();

	if (pitch.getTile(player.getPosition()->getX(), player.getPosition()->getY())->getArea() == Area::Penalty)
	{
		int rnd = rand() % (10 / player.getLevel()) + 1;
		
		int chance = 10 * player.getLevel();

		std::cout << player.getName() << " dringt in den Strafraum ein und schiesst auf das Tor! (Chance: " << chance << "%)" << std::endl;

		if (rnd == 1)
		{
			std::cout << "TOOOOR!!!" << std::endl;
		}
		else
		{
			std::cout << "Daneben!" << std::endl;
		}

		player.setState(State::Idle);
		player.hasBall(false);
		ball.setPosition(Position(8, 5));
	}

	endTurn(player, pitch);
}