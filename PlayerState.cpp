#pragma once

#include "PlayerState.h"
#include "Player.h"
#include "Tile.h"
#include "Position.h"
#include "Pitch.h"

// Basisklasse alle Zustände der Spieler

// Entfernt einen Spieler vor seiner Bewegung aus der Spielerliste des Feldes, auf dem er steht
void PlayerState::beginTurn(Player& player, Pitch& pitch)
{
	pitch.getTile(player.getPosition()->getX(), player.getPosition()->getY())->removePlayer(player);
}

// Fügt einen Spieler nach seiner Bewegung der Spielerliste des Feldes, auf dem er steht, hinzu
void PlayerState::endTurn(Player& player, Pitch& pitch)
{
	pitch.getTile(player.getPosition()->getX(), player.getPosition()->getY())->addPlayer(player);
}