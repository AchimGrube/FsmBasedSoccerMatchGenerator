#pragma once

#include "PlayerState.h"

class Player;
class Match;

class PlayerStateInteract : public PlayerState
{
public:

	PlayerStateInteract();
	~PlayerStateInteract();

	void doAction(Player&, Match&) override;
};