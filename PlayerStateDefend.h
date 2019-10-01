#pragma once

#include "IPlayerState.h"

class PlayerStateDefend :	public IPlayerState
{
public:

	void doAction(Player&, Ball&, Position&) override;

private:

};