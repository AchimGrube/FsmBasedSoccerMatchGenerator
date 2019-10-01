#pragma once

#include "IPlayerState.h"

class PlayerStateAttack : public IPlayerState
{
public:

	void doAction(std::string&, Position&) override;

private:

};