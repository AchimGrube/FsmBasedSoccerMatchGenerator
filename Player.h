#pragma once

#include <string>

#include "Entity.h"
#include "FiniteStateMachine.h"

using std::string;

class Player : public Entity
{
public:

	Player(std::string name) { this->name = name; };

	string getName() { return name; };

	State getState() { return state; };
	void setState(State state) { this->state = state; };

private:

	string name;
	State state = State::Idle;
};