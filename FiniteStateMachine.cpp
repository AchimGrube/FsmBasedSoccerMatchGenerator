#pragma once

#include "FiniteStateMachine.h"
#include "PlayerStateIdle.h"
#include "PlayerStateMove.h"
#include "PlayerStateInteract.h"
#include "PlayerStateAttack.h"

FiniteStateMachine::FiniteStateMachine()
{
}

FiniteStateMachine::~FiniteStateMachine()
{
}

PlayerState* FiniteStateMachine::updateState(State state)
{
	switch (state)
	{
	case State::Idle:
		return new PlayerStateIdle();
	case State::Move:
		return new PlayerStateMove();
	case State::Interact:
		return new PlayerStateInteract();
	case State::Attack:
		return new PlayerStateAttack();
	default:
		return nullptr;
	}
}