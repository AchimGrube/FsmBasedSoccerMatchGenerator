#pragma once

#include <memory>

#include "IPlayerState.h"

enum class State
{
	Idle, Move, Interaction, Attack
};

class FiniteStateMachine
{
public:

	std::shared_ptr<IPlayerState> updateState(State state);

private:

};