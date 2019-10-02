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
		drawOnConsole(0, 0, true);
		cout << "Minute " << minute << ": " << endl;
		nextMinute();
		cout << endl;
	}
}

void Match::init()
{
	pitch = Pitch();

	NameGenerator* ng = new NameGenerator();
	srand((unsigned)std::time(NULL));

	for (int i = 0; i < sizeof(teamA) / sizeof(teamA[0]); i++)
	{
		teamA[i] = Player(ng->getName());
	}

	for (int i = 0; i < sizeof(teamB) / sizeof(teamB[0]); i++)
	{
		teamB[i] = Player(ng->getName());
	}

	delete ng;
}

void Match::nextMinute()
{
	vector<Player*> players = vector<Player*>();

	for (auto& player : teamA)
	{
		players.push_back(&player);
	}
	for (auto& player : teamB)
	{
		players.push_back(&player);
	}

	std::random_shuffle(players.begin(), players.end());

	for (auto& player : players)
	{
		printf("Player: %s\n", player->getName().c_str());
		printf("Position: %d,%d\n", player->getPosition()->getX(), player->getPosition()->getY());
		printf("has Ball: %s\n", player->hasBall() ? "true" : "false");
		printf("Target: %d,%d\n", player->getTarget()->getX(), player->getTarget()->getY());
		string playerState;
		switch (player->getState())
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
		printf("Ball Position: %d,%d\n", ball.getPosition()->getX(), ball.getPosition()->getY());
		player->performRound(ball);
	}

	addMinute();

	std::this_thread::sleep_for(std::chrono::seconds(3));
}

void Match::drawOnConsole(int x, int y, bool clearLine)
{
	COORD coord;
	coord.Y = y;

	if (clearLine)
	{
		for (int i = 0; i < 121; i++)
		{
			coord.X = i;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			cout << " ";
		}
	}

	coord.X = x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}