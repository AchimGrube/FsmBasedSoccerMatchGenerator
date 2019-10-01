#include "FiniteStateMachine.h"
#include "PlayerStateIdle.h"
#include "PlayerStateMove.h"
#include "PlayerStateDefend.h"
#include "PlayerStateAttack.h"

IPlayerState* FiniteStateMachine::updateState(State state)
{
	switch (state)
	{
	case State::Idle:
		return new PlayerStateIdle();
	case State::Move:
		return new PlayerStateMove();
	case State::Defend:
		return new PlayerStateDefend();
	case State::Attack:
		return new PlayerStateAttack();
	default:
		return nullptr;
	}
}