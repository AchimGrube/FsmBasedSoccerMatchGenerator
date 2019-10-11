#pragma once

#include "PlayerStateMove.h"
#include "Player.h"
#include "Ball.h"
#include "Position.h"
#include "FiniteStateMachine.h"
#include "Match.h"

// abgeleitete Klasse von <PlayerState> für die Logik, wenn ein Spieler den Status "Move" hat

PlayerStateMove::PlayerStateMove()
{
}

PlayerStateMove::~PlayerStateMove()
{
}

void PlayerStateMove::doAction(Player& player, Match& match)
{
	beginTurn(player, *match.getPitch());

	player.setTarget(*match.getBall()->getPosition());
	player.move(*player.getTarget());

	int playerPosX = player.getPosition()->getX();
	int playerPosY = player.getPosition()->getY();
	Position ballPos = *match.getBall()->getPosition();

	if (playerPosX == ballPos.getX() && playerPosY == ballPos.getY())
	{
		if (match.getPitch()->getTile(playerPosX, playerPosY)->getPlayers()->size() > 0)
		{
			if (!player.hasBall())
			{
				player.setState(State::Interact);
				player.setTarget(ballPos);
			}
	}
		else
		{
			processText(player.getName() + "[" + player.getTeam() + "] holt sich den freien Ball.\n\n", match);
			pause(Match::textSpeed);

			player.hasBall(true);
			player.setState(State::Attack);
			player.setTarget(*player.getOpponentGoalPosition());
		}
	}

	endTurn(player, *match.getPitch());
}