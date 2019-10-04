#include "FiniteStateMachine.h"
#include "PlayerStateIdle.h"
#include "PlayerStateMove.h"
#include "PlayerStateDefend.h"
#include "PlayerStateAttack.h"

std::shared_ptr<IPlayerState> FiniteStateMachine::updateState(State state)
{
	switch (state)
	{
	case State::Idle:
		return std::shared_ptr<IPlayerState>(new PlayerStateIdle);
	case State::Move:
		return std::shared_ptr<IPlayerState>(new PlayerStateMove);
	case State::Defend:
		return std::shared_ptr<IPlayerState>(new PlayerStateDefend);
	case State::Attack:
		return std::shared_ptr<IPlayerState>(new PlayerStateAttack);
	default:
		return nullptr;
	}
}