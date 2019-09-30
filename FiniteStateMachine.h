#pragma once

enum class State
{
	Idle, Move, Defend, Attack
};

class FiniteStateMachine
{
public:

	State updateState(State state);

private:

	State state;
};