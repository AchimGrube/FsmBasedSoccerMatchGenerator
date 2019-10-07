#pragma once

#include <string>

#include "Ball.h"
#include "Position.h"

class Player;
class Pitch;
class Match;

class IPlayerState abstract
{
public:

	void beginTurn(Player&, Pitch&);
	virtual void doAction(Player&, Pitch&, Ball&) = 0;
	void endTurn(Player&, Pitch&);

private:

};