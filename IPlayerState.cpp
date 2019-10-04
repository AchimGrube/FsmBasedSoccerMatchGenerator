#include "IPlayerState.h"
#include "Pitch.h"

void IPlayerState::beginTurn(Player& player, Pitch& pitch)
{
	pitch.getTile(player.getPosition()->getX(), player.getPosition()->getY())->removePlayer(player);
}

void IPlayerState::endTurn(Player& player, Pitch& pitch)
{
	pitch.getTile(player.getPosition()->getX(), player.getPosition()->getY())->addPlayer(player);
}
