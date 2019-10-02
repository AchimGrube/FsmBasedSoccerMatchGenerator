#include "Match.h"

Match::Match()
{
	length = 90;
	minute = 1;
	auto ballPos = new Position(Pitch::sizeX / 2, Pitch::sizeY / 2);
	ball.setPosition(*ballPos);
}

Ball * Match::getBall()
{
	return &ball;
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

pair<int, int> Match::getScore() const
{
	return score;
}

void Match::setScore(int scoreTeamA, int scoreTeamB)
{
	score.first = scoreTeamA;
	score.second = scoreTeamB;
}

bool Match::hasEnded() const
{
	return minute > length;
}

void Match::start()
{
	init();

	cout << endl << "Spielstart:" << endl << endl;

	while (!hasEnded())
	{
		setConsoleCursorPosition(0, 0, true);
		cout << "Minute " << minute << ": " << endl;
		cout << "==========" << endl << endl;
		nextMinute();
	}
}

void Match::init()
{
	pitch = Pitch();

	NameGenerator* ng = new NameGenerator();
	srand((unsigned)std::time(NULL));

	for (size_t i = 0; i < teamA.size(); i++)
	{
		teamA.at(i) = Player(ng->getName());

		players.push_back(&teamA.at(i));
	}

	for (size_t i = 0; i < teamB.size(); i++)
	{
		teamB.at(i) = Player(ng->getName());

		players.push_back(&teamB.at(i));
	}

	delete ng;
}

void Match::nextMinute()
{
	std::random_shuffle(players.begin(), players.end());

	for (auto& player : players)
	{
		printMatchLines(*player);
		player->performRound(ball);
	}
	printf("Ball Position: %d,%d\n", ball.getPosition()->getX(), ball.getPosition()->getY());

	addMinute();

	std::this_thread::sleep_for(std::chrono::seconds(3));
}

void Match::printMatchLines(Player& player)
{
	printf("Player: %s\n", player.getName().c_str());
	printf("Position: %d,%d\n", player.getPosition()->getX(), player.getPosition()->getY());
	printf("has Ball: %s\n", player.hasBall() ? "true" : "false");
	printf("Target: %d,%d\n", player.getTarget()->getX(), player.getTarget()->getY());
	string playerState;
	switch (player.getState())
	{
	case State::Idle:
		playerState = "Idle";
		break;
	case State::Move:
		playerState = "Move";
		break;
	case State::Defend:
		playerState = "Defend";
		break;
	case State::Attack:
		playerState = "Attack";
		break;
	default:
		playerState = "";
		break;
	}
	printf("State: %s\n\n", playerState.c_str());
}

void Match::setConsoleCursorPosition(int x, int y, bool line)
{
	COORD coord;

	if (line)
	{
		for (int x = 0; x < 21; x++)
		{
			for (int y = 0; y < 16; y++)
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