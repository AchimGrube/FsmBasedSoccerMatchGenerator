#pragma once

#include <string>
#include <memory>

#include "FiniteStateMachine.h"
#include "Ball.h"

using std::string;

class Player : public Entity
{
public:

	Player();
	Player(string name);

	string getName() const;

	int getLevel() const;
	void setLevel(int);

	std::unique_ptr<Position> getTarget();
	void setTarget(const Position&);

	State getState() const;
	void setState(const State&);

	bool hasBall() const;
	void hasBall(bool);

	void performRound(Ball&);

private:

	string name;
	int level;
	Position target;
	State state;
	bool playerHasBall;

	std::unique_ptr<IPlayerState> _playerState;
	FiniteStateMachine _fsm;
};