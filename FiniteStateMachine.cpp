#include "FiniteStateMachine.h"
#include "PlayerStateIdle.h"
#include "PlayerStateMove.h"
#include "PlayerStateDefend.h"
#include "PlayerStateAttack.h"

std::unique_ptr<IPlayerState> FiniteStateMachine::updateState(State state)
{
	switch (state)
	{
	case State::Idle:
		return std::unique_ptr<IPlayerState>(new PlayerStateIdle);
	case State::Move:
		return std::unique_ptr<IPlayerState>(new PlayerStateMove);
	case State::Defend:
		return std::unique_ptr<IPlayerState>(new PlayerStateDefend);
	case State::Attack:
		return std::unique_ptr<IPlayerState>(new PlayerStateAttack);
	default:
		return nullptr;
	}
}