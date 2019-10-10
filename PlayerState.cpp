#pragma once

#include "PlayerState.h"
#include "Player.h"
#include "Tile.h"
#include "Position.h"
#include "Pitch.h"

void PlayerState::beginTurn(Player& player, Pitch& pitch)
{
	pitch.getTile(player.getPosition()->getX(), player.getPosition()->getY())->removePlayer(player);
}

void PlayerState::endTurn(Player& player, Pitch& pitch)
{
	pitch.getTile(player.getPosition()->getX(), player.getPosition()->getY())->addPlayer(player);
}