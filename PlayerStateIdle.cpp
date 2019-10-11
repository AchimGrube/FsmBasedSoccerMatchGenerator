#pragma once

#include "PlayerStateIdle.h"

#include "Player.h"
#include "FiniteStateMachine.h"
#include "Ball.h"
#include "Match.h"

PlayerStateIdle::PlayerStateIdle()
{
}

PlayerStateIdle::~PlayerStateIdle()
{
}

void PlayerStateIdle::doAction(Player& player, Match& match)
{
	beginTurn(player, *match.getPitch());

	if (!player.hasBall())
	{
		player.setState(State::Move);
		player.setTarget(*match.getBall()->getPosition());
	}

	endTurn(player, *match.getPitch());
}