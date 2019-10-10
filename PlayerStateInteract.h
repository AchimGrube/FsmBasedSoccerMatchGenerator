#pragma once

#include "PlayerState.h"

class Player;
class Pitch;
class Ball;

class PlayerStateInteract : public PlayerState
{
public:

	PlayerStateInteract();
	~PlayerStateInteract();

	void doAction(Player&, Pitch&, Ball&) override;
};