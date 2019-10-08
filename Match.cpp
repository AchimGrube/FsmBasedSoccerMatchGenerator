#include "Match.h"

pair<int, int> Match::score;

Match::Match()
{
	length = 90;
	minute = 1;
	ball.setPosition(Position(rand() % Pitch::sizeX, rand() % Pitch::sizeY));
}

std::shared_ptr<Ball> Match::getBall()
{
	return std::make_shared<Ball>(ball);
}

int Match::getLength() const
{
	return length;
}

int Match::getMinute() const
{
	return minute;
}

void Match::addMinute()
{
	minute++;
}

bool Match::hasEnded() const
{
	return minute > length;
}

void Match::addGoalTeamA()
{
	score.first++;
}

void Match::addGoalTeamB()
{
	score.second++;
}

void Match::resetScore()
{
	score.first = score.second = 0;
}

void Match::start()
{
	init();

	Match::resetScore();

	cout << endl << "Spielstart:" << endl << endl;

	while (!hasEnded())
	{
		//setConsoleCursorPosition(0, 0, true);
		//cout << "Minute " << minute << "   " << "[" << score.first << ":" << score.second << "]" << endl;
		printf("Minute %02d   [%d:%d]\n", minute, score.first, score.second);
		//cout << "==========" << endl << endl;
		nextMinute();
	}

	std::cout << endl << "Das Spiel endete " << score.first << ":" << score.second << endl << endl;
}

void Match::init()
{
	pitch = Pitch();

	std::shared_ptr<Generator> ng = std::make_shared<Generator>();
	srand((unsigned)std::time(NULL));

	Position teamAGoal = Position(0, 5);
	Position teamBGoal = Position(16, 5);

	for (size_t i = 0; i < teamA.size(); i++)
	{
		teamA.at(i) = ng->getNewPlayer();
		teamA.at(i).setOpponentGoalPosition(teamBGoal);
		pitch.addPlayerOnTile(teamA.at(i), teamA.at(i).getPosition()->getX(), teamA.at(i).getPosition()->getY());
		players.push_back(&teamA.at(i));
	}

	for (size_t i = 0; i < teamB.size(); i++)
	{
		teamB.at(i) = ng->getNewPlayer();
		teamB.at(i).setOpponentGoalPosition(teamAGoal);
		pitch.addPlayerOnTile(teamB.at(i), teamB.at(i).getPosition()->getX(), teamB.at(i).getPosition()->getY());
		players.push_back(&teamB.at(i));
	}
}

void Match::nextMinute()
{
	std::random_shuffle(players.begin(), players.end());

	//printf("Ball Position: %d,%d\n\n", ball.getPosition()->getX(), ball.getPosition()->getY());

	for (auto& player : players)
	{
		//printMatchLines(*player);
		player->performRound(pitch, ball);
	}

	if (pitch.getTile(ball.getPosition()->getX(), ball.getPosition()->getY())->getArea() == Area::Out)
	{
		std::cout << "Der Ball rollt ins Aus." << std::endl;
		ball.setPosition(Position(8, 5));
	}

	addMinute();

	std::cout << std::endl;

	//std::this_thread::sleep_for(std::chrono::milliseconds(500));
	//std::cin.ignore();
}

void Match::printMatchLines(Player & player)
{
	printf("Player: %s\n", player.getName().c_str());
	printf("Level: %d\n", player.getLevel());
	printf("Position: %d,%d\n", player.getPosition()->getX(), player.getPosition()->getY());
	printf("has Ball: %s\n", player.hasBall() ? "true" : "false");
	printf("Target: %d,%d\n", player.getTarget()->getX(), player.getTarget()->getY());
	printf("State: %d\n", player.getState());
	printf("Area: %d\n\n", pitch.getTile(player.getPosition()->getX(), player.getPosition()->getY())->getArea());
}

void Match::setConsoleCursorPosition(int x, int y, bool clearLines)
{
	COORD coord;

	if (clearLines)
	{
		for (int x = 0; x < 21; x++)
		{
			for (int y = 0; y < 20; y++)
			{
				coord.X = x;
				coord.Y = y;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
				cout << " ";
			}
		}
	}

	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}