#include "IPlayerState.h"
#include "Pitch.h"

void IPlayerState::enter(Player& player, Pitch& pitch)
{
	pitch.getTile(player.getPosition()->getX(), player.getPosition()->getY())->removePlayer(&player);
}

void IPlayerState::leave(Player& player, Pitch& pitch)
{
	pitch.getTile(player.getPosition()->getX(), player.getPosition()->getY())->addPlayer(&player);
}
