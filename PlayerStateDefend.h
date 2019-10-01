#pragma once

#include "IPlayerState.h"

class PlayerStateDefend :	public IPlayerState
{
public:

	void doAction(std::string&, Ball&, Position&) override;

private:

};