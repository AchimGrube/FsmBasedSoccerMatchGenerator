#pragma once

#include <string>

#include "Position.h"

class IPlayerState abstract
{
public:

	virtual void doAction(std::string&, Position&) = 0;

private:

};