#pragma once

#include "PlayerStateIdle.h"

#include "Player.h"
#include "FiniteStateMachine.h"
#include "Ball.h"

PlayerStateIdle::PlayerStateIdle()
{
}

PlayerStateIdle::~PlayerStateIdle()
{
}

void PlayerStateIdle::doAction(Player& player, Pitch& pitch, Ball& ball)
{
	beginTurn(player, pitch);

	if (!player.hasBall())
	{
		player.setState(State::Move);
		player.setTarget(*ball.getPosition());
	}

	endTurn(player, pitch);
}