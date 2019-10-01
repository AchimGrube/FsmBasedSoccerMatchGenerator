#include "Player.h"

Player::Player(string name)
{
	this->name = name;
}

string Player::getName() const
{
	return name;
}

State Player::getState() const
{
	return state;
}

void Player::setState(State state)
{
	this->state = state;
}

void Player::performRound()
{

}