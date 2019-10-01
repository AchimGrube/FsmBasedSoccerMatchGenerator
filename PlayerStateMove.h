#pragma once

#include "IPlayerState.h"

class PlayerStateMove :	public IPlayerState
{
public:
	
	void doAction(std::string&, Position&) override;

private:

};