#pragma once

#include "IPlayerState.h"

class PlayerStateIdle :	public IPlayerState
{
public:

	void doAction(std::string&, Ball&, Position&) override;

private:

};