#pragma once

#include "PlayerState.h"

class Player;
class Pitch;
class Ball;

class PlayerStateAttack : public PlayerState
{
public:

	PlayerStateAttack();
	~PlayerStateAttack();

	void doAction(Player&, Pitch&, Ball&) override;
};