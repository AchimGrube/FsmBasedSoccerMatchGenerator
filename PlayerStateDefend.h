#pragma once

#include "IPlayerState.h"

class PlayerStateDefend :	public IPlayerState
{
public:

	void doAction(Player player, Ball ball, Position target) override;

private:

};