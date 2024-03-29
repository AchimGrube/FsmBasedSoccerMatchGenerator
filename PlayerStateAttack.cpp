#pragma once

#include "PlayerStateAttack.h"
#include "Player.h"
#include "Ball.h"
#include "Position.h"
#include "Pitch.h"
#include "Tile.h"
#include "Match.h"
#include "FiniteStateMachine.h"

// abgeleitete Klasse von <PlayerState> f�r die Logik, wenn ein Spieler den Status "Attack" hat

PlayerStateAttack::PlayerStateAttack()
{
}

PlayerStateAttack::~PlayerStateAttack()
{
}

void PlayerStateAttack::doAction(Player& player, Match& match)
{
	beginTurn(player, *match.getPitch());

	player.setTarget(*player.getOpponentGoalPosition());
	player.move(*player.getTarget());
	match.getBall()->move(*player.getPosition());

	int playerPosX = player.getPosition()->getX();
	int playerPosY = player.getPosition()->getY();
	
	if (match.getPitch()->getTile(playerPosX, playerPosY)->getArea() == Area::Penalty && player.hasBall())
	{
		int rndPlayer = rand() % (10 / player.getLevel()) + 1;
		int chance = 10 * player.getLevel();

		processText(player.getName() + "[" + player.getTeam() + "] dringt in den Strafraum ein und schiesst auf das Tor! (Chance: " + std::to_string(chance) + "%)\n", match);
		pause(Match::textSpeed);

		if (rndPlayer == 1)
		{
			int rndGoalkeeper = rand() % (10 / ((rand() % 5) + 1)) + 1;

			if (rndPlayer <= rndGoalkeeper)
			{
				processText("TOOOOOR!\n\n", match);

				if (player.getOpponentGoalPosition()->getX() > 8)
				{
					match.addGoalTeamA();
				}
				else
				{
					match.addGoalTeamB();
				}

				match.getBall()->setPosition(8, 5);
			}
			else
			{
				processText("Der Torwart haelt den Ball.\n\n", match);
				match.getBall()->setPosition(rand() % Pitch::SIZE_X, rand() % Pitch::SIZE_Y);
			}
		}
		else
		{
			processText("Der Schuss geht daneben.\n\n", match);
			match.getBall()->setPosition(rand() % Pitch::SIZE_X, rand() % Pitch::SIZE_Y);
		}
		pause(Match::textSpeed);

		player.hasBall(false);
		player.setState(State::Idle);

		for (int x = 0; x < Pitch::SIZE_X; x++)
		{
			for (int y = 0; y < Pitch::SIZE_Y; y++)
			{
				std::list<Player*> playerList = *match.getPitch()->getTile(x, y)->getPlayers();

				for (auto element : playerList)
				{
					element->setState(State::Idle);
				}
			}
		}
	}

	endTurn(player, *match.getPitch());
}