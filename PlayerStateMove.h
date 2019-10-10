#pragma once

#include "PlayerState.h"

class Player;
class Pitch;
class Ball;

class PlayerStateMove :	public PlayerState
{
public:

	PlayerStateMove();
	~PlayerStateMove();

	void doAction(Player&, Pitch&, Ball&) override;
};