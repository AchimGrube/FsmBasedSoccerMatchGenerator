#include "Player.h"

Player::Player(string name)
{
	this->name = name;
	state = State::Idle;
	playerHasBall = false;
	_fsm = FiniteStateMachine();
	_playerState = nullptr;
}

string Player::getName() const
{
	return name;
}

Position* Player::getTarget()
{
	return &target;
}

void Player::setTarget(const Position& target)
{
	this->target = target;
}

State Player::getState() const
{
	return state;
}

void Player::setState(const State& state)
{
	this->state = state;
}

bool Player::hasBall() const
{
	return playerHasBall;
}

void Player::hasBall(bool hasBall)
{
	this->playerHasBall = hasBall;
}

void Player::performRound()
{
	_playerState = _fsm.updateState(getState());
	_playerState->doAction(name, target);
}