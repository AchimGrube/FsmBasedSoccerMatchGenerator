#include "Player.h"

Player::Player(string name)
{
	this->name = name;
}

string Player::getName()
{
	return name;
}

State Player::getState()
{
	return state;
}

void Player::setState(State state)
{
	this->state = state;
}
