#pragma once

#include "Player.h"
#include "PlayerState.h"
#include "Match.h"

Player::Player()
{
	this->_fsm = nullptr;
	this->_playerState = nullptr;
	this->level = 0;
	this->opponentGoalPosition = nullptr;
	this->playerHasBall = false;
	this->state = State::Idle;
	this->target = nullptr;
}

Player::Player(std::string name)
{
	this->name = name;
}

Player::~Player()
{
}

std::string Player::getName() const
{
	return this->name;
}

int Player::getLevel() const
{
	return this->level;
}

void Player::setLevel(int level)
{
	this->level = level;
}

State Player::getState() const
{
	return this->state;
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

std::shared_ptr<Position> Player::getTarget()
{
	return std::shared_ptr<Position>(this->target);
}

void Player::setTarget(Position& position)
{
	this->target = std::make_shared<Position>(position);
}

std::shared_ptr<Position> Player::getOpponentGoalPosition()
{
	return std::shared_ptr<Position>(this->opponentGoalPosition);
}

void Player::setOpponentGoalPosition(Position& position)
{
	this->opponentGoalPosition = std::make_shared<Position>(position);
}

void Player::performRound(Match& match)
{
	this->_playerState = _fsm->updateState(getState());
	this->_playerState->doAction(*this, match);
}