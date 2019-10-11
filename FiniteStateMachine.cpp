#pragma once

#include "FiniteStateMachine.h"
#include "PlayerStateIdle.h"
#include "PlayerStateMove.h"
#include "PlayerStateInteract.h"
#include "PlayerStateAttack.h"

// Endlicher Automat, um zwischen den verfügbaren Zuständen der Spieler zu wechseln

FiniteStateMachine::FiniteStateMachine()
{
}

FiniteStateMachine::~FiniteStateMachine()
{
}

// Liest den aktuellen Zustand des Spielers und gibt ein neues Objekt der von <PlayerState> abgeleiteten Klasse zurück, welche die jeweilige Logik des Zustands beinhaltet
PlayerState* FiniteStateMachine::updateState(State state)
{
	switch (state)
	{
	case State::Idle:
		return new PlayerStateIdle();
	case State::Move:
		return new PlayerStateMove();
	case State::Interact:
		return new PlayerStateInteract();
	case State::Attack:
		return new PlayerStateAttack();
	default:
		return nullptr;
	}
}