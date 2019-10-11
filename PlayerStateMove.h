#pragma once

#include "PlayerState.h"

class Player;
class Match;

class PlayerStateMove :	public PlayerState
{
public:

	PlayerStateMove();
	~PlayerStateMove();

	void doAction(Player&, Match&) override;
};