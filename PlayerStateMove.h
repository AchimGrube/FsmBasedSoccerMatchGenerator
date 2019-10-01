#pragma once

#include "IPlayerState.h"

class PlayerStateMove :	public IPlayerState
{
public:
	
	void doAction(Player&, Ball&, Position&) override;

private:

};