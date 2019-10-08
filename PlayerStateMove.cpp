#include "PlayerStateMove.h"
#include "Match.h"

void PlayerStateMove::doAction(Player& player, Pitch& pitch, Ball& ball)
{
	beginTurn(player, pitch);

	player.setTarget(*ball.getPosition());
	player.move(*player.getTarget());
	
	if (player.getPosition()->getX() == ball.getPosition()->getX() && player.getPosition()->getY() == ball.getPosition()->getY())
	{
		if (pitch.getPlayersOnTiles(player.getPosition()->getX(), player.getPosition()->getY())->size() > 0)
		{
			if (!player.hasBall())
			{
				player.hasBall(false);
				player.setState(State::Defend);
				player.setTarget(*ball.getPosition());
			}
			//else
			//{
			//	std::cout << player.getName() << " setzt zum Dribbling an";
			//	if (rand() % 2 == 1)
			//	{
			//		std::cout << ", bleibt aber haengen und verliert den Ball.\n\n";
			//		player.hasBall(false);
			//		player.setState(State::Idle);
			//		player.setTarget(Position(0, 0));
			//	}
			//	else
			//	{
			//		std::cout << ", tanzt durch alle Gegner und startet einen Angriff.\n\n";
			//		player.hasBall(true);
			//		player.setState(State::Attack);
			//		player.setTarget(*player.getOpponentGoalPosition());
			//	}
			//}
		}
		else
		{
			std::cout << player.getName() << " holt sich den frei liegenden Ball.\n\n";
			std::this_thread::sleep_for(std::chrono::milliseconds(Match::textSpeed));
			player.hasBall(true);
			player.setState(State::Attack);
			player.setTarget(*player.getOpponentGoalPosition());
		}
	}

	endTurn(player, pitch);
}