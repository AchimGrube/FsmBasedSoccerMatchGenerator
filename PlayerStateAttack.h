#pragma once

#include "PlayerState.h"

class Player;
class Match;

class PlayerStateAttack : public PlayerState
{
public:

	PlayerStateAttack();
	~PlayerStateAttack();

	void doAction(Player&, Match&) override;
};