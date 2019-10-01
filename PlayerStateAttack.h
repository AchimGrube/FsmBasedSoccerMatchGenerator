#pragma once

#include "IPlayerState.h"

class PlayerStateAttack : public IPlayerState
{
public:

	void doAction(Player player, Ball ball, Position target) override;

private:

};