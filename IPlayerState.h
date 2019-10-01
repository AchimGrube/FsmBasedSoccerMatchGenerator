#pragma once

#include <string>

#include "Ball.h"
#include "Position.h"

class IPlayerState abstract
{
public:

	virtual void doAction(std::string&, Ball&, Position&) = 0;

private:

};