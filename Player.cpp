#include "Player.h"

Player::Player()
{
	state = State::Idle;
	playerHasBall = false;
	_fsm = FiniteStateMachine();
	_playerState = nullptr;
}

Player::Player(string name) : Player()
{
	this->name = name;
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

void Player::performRound(Ball& ball)
{
	_playerState = _fsm.updateState(getState());
	_playerState->doAction(name, ball, target);
}