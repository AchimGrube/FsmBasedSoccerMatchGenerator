#pragma once

#include <string>

#include "Ball.h"
#include "Position.h"

class Player;
class Pitch;

class IPlayerState abstract
{
public:

	void enter(Player&, Pitch&);
	virtual void doAction(Player&, Pitch&, Ball&, Position&) = 0;
	void leave(Player&, Pitch&);

private:

};