#pragma once

#include "IPlayerState.h"

class PlayerStateAttack : public IPlayerState
{
public:

	void doAction(Player&, Ball&, Position&) override;

private:

};