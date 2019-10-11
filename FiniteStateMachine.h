#pragma once

#include <memory>

class PlayerState;

enum class State
{
	Idle, Move, Interact, Attack
};

class FiniteStateMachine
{
public:

	FiniteStateMachine();
	~FiniteStateMachine();

	std::shared_ptr<PlayerState> updateState(State);
};