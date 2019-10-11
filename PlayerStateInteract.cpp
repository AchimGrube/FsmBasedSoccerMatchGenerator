#pragma once

#include <list>

#include "PlayerStateInteract.h"
#include "Player.h"
#include "Position.h"
#include "Tile.h"
#include "Pitch.h"
#include "Match.h"
#include "FiniteStateMachine.h"

// abgeleitete Klasse von <PlayerState> für die Logik, wenn ein Spieler den Status "Interact" hat

PlayerStateInteract::PlayerStateInteract()
{
}

PlayerStateInteract::~PlayerStateInteract()
{
}

void PlayerStateInteract::doAction(Player& player, Match& match)
{
	beginTurn(player, *match.getPitch());

	int playerPosX = player.getPosition()->getX();
	int playerPosY = player.getPosition()->getY();

	int rndPlayer = rand() % (10 / player.getLevel()) + 1;
	
	std::list<Player*> playerList = *match.getPitch()->getTile(playerPosX, playerPosY)->getPlayers();

	for (auto opponent : playerList)
	{
		if (!opponent->hasBall())
		{
			continue;
		}

		if (player.getOpponentGoalPosition()->getX() == opponent->getOpponentGoalPosition()->getX())
		{
			if (player.getLevel() > opponent->getLevel())
			{
				processText(opponent->getName() + "[" + opponent->getTeam() + "] passt den Ball zu " + player.getName() + "[" + player.getTeam() + "]\n\n", match);
				pause(Match::textSpeed);

				player.hasBall(true);
				player.setState(State::Attack);
				player.setTarget(*player.getOpponentGoalPosition());

				opponent->hasBall(false);
				opponent->setState(State::Idle);
			}
			break;
		}

		processText(player.getName() + "[" + player.getTeam() + "] geht in einen Zweikampf mit " + opponent->getName() + "[" + opponent->getTeam() + "]", match);
		pause(Match::textSpeed);

		int rndOpponent = rand() % (opponent->getLevel()) + 1;

		if (rndPlayer >= rndOpponent)
		{
			processText(" und nimmt ihm den Ball ab.\n\n", match);

			player.hasBall(true);
			player.setState(State::Attack);
			player.setTarget(*player.getOpponentGoalPosition());

			opponent->hasBall(false);
			opponent->setState(State::Idle);
		}
		else
		{
			processText(", doch der bleibt am Ball.\n\n", match);

			player.hasBall(false);
			player.setState(State::Idle);

			opponent->hasBall(true);
			opponent->setState(State::Attack);
			opponent->setTarget(*opponent->getOpponentGoalPosition());
		}
		pause(Match::textSpeed);
	}

	player.setState(State::Idle);

	endTurn(player, *match.getPitch());
}