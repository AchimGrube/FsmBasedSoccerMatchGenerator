#pragma once

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

	PlayerState* updateState(State);
};