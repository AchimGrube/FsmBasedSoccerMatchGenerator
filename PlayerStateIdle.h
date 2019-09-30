#pragma once

#include "IPlayerState.h"

class PlayerStateIdle :	public IPlayerState
{
public:

	void doAction() override;

private:

};