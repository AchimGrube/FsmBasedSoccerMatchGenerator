#pragma once

#include <string>

#include "Entity.h"
#include "FiniteStateMachine.h"

using std::string;

class Player : public Entity
{
public:

	Player(string name);

	string getName();

	State getState();
	void setState(State state);

private:

	string name;
	State state = State::Idle;
};