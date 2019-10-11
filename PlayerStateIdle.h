#pragma once

#include "PlayerState.h"

class Player;
class Match;

class PlayerStateIdle :	public PlayerState
{
public:

	PlayerStateIdle();
	~PlayerStateIdle();

	void doAction(Player&, Match&) override;
};