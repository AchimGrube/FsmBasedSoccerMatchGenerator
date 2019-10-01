#pragma once

#include <string>

#include "Entity.h"
#include "FiniteStateMachine.h"

using std::string;

class Player : public Entity
{
public:

	Player(string name);

	string getName() const;

	State getState() const;
	void setState(State state);

	void performRound();

private:

	string name;
	State state = State::Idle;
};