#pragma once

#include "IPlayerState.h"

enum class State
{
	Idle, Move, Defend, Attack
};

class FiniteStateMachine
{
public:

	IPlayerState* updateState(State state);

private:

};