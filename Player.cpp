#include "Player.h"
#include "Pitch.h"

Player::Player()
{
	level = 0;
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

int Player::getLevel() const
{
	return level;
}

void Player::setLevel(int skillLevel)
{
	this->level = skillLevel;
}

std::shared_ptr<Position> Player::getTarget()
{
	return std::make_shared<Position>(target);
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

void Player::performRound(Pitch& pitch, Ball& ball)
{
	_playerState = std::shared_ptr<IPlayerState>(_fsm.updateState(getState()));
	//_playerState->enter(*this, pitch);
	_playerState->doAction(*this, pitch, ball, target);
	//_playerState->leave(*this, pitch);
}