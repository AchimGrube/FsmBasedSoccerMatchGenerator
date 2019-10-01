#pragma once

#include "IPlayerState.h"

class PlayerStateMove :	public IPlayerState
{
public:
	
	void doAction(std::string&, Ball&, Position&) override;

private:

};