#pragma once

#include <string>

#include "Ball.h"
#include "Position.h"

class Player;
class Pitch;

class IPlayerState abstract
{
public:

	void beginTurn(Player&, Pitch&);
	virtual void doAction(Player&, Pitch&, Ball&, Position&) = 0;
	void endTurn(Player&, Pitch&);

private:

};