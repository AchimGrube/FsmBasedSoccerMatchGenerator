#pragma once

#include "IPlayerState.h"
#include "Player.h"

class PlayerStateDefend :	public IPlayerState
{
public:

	void doAction(Player&, Ball&, Position&) override;

private:

};