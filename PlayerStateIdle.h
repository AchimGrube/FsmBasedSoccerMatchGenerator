#pragma once

#include "IPlayerState.h"

class PlayerStateIdle :	public IPlayerState
{
public:

	void doAction(Player player, Ball ball, Position target) override;

private:

};