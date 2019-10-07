#include "IPlayerState.h"
#include "Pitch.h"

void IPlayerState::beginTurn(Player& player, Pitch& pitch)
{
	pitch.removePlayerOnTile(player, player.getPosition()->getX(), player.getPosition()->getY());
}

void IPlayerState::endTurn(Player& player, Pitch& pitch)
{
	pitch.addPlayerOnTile(player, player.getPosition()->getX(), player.getPosition()->getY());
}