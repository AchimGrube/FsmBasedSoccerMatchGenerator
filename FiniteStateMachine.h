#pragma once

#include <memory>

#include "IPlayerState.h"

enum class State
{
	Idle, Move, Defend, Attack
};

class FiniteStateMachine
{
public:

	std::unique_ptr<IPlayerState> updateState(State state);

private:

};