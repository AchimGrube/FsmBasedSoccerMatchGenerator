#pragma once

#include "IPlayerState.h"
#include "Player.h"

class PlayerStateIdle :	public IPlayerState
{
public:

	void doAction(Player&, Ball&, Position&) override;

private:

};