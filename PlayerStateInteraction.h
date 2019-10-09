#pragma once

#include "IPlayerState.h"
#include "Player.h"
#include "Pitch.h"

class PlayerStateInteraction :	public IPlayerState
{
public:

	void doAction(Player&, Pitch&, Ball&) override;

private:

};