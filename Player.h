#pragma once

#include <string>

#include "Entity.h"
#include "FiniteStateMachine.h"
#include "IPlayerState.h"

using std::string;

class Player : public Entity
{
public:

	Player(string name);

	string getName() const;

	Position* getTarget();
	void setTarget(const Position&);

	State getState() const;
	void setState(const State&);

	bool hasBall() const;
	void hasBall(bool);

	void performRound();

private:

	string name;
	Position target;
	State state;
	bool playerHasBall;

	IPlayerState* _playerState;
	FiniteStateMachine _fsm;
};