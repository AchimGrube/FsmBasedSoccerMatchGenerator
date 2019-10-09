#include "FiniteStateMachine.h"
#include "PlayerStateIdle.h"
#include "PlayerStateMove.h"
#include "PlayerStateInteraction.h"
#include "PlayerStateAttack.h"

std::shared_ptr<IPlayerState> FiniteStateMachine::updateState(State state)
{
	switch (state)
	{
	case State::Idle:
		return std::shared_ptr<IPlayerState>(new PlayerStateIdle);
	case State::Move:
		return std::shared_ptr<IPlayerState>(new PlayerStateMove);
	case State::Interaction:
		return std::shared_ptr<IPlayerState>(new PlayerStateInteraction);
	case State::Attack:
		return std::shared_ptr<IPlayerState>(new PlayerStateAttack);
	default:
		return nullptr;
	}
}