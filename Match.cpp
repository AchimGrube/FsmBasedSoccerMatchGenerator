#include "Match.h"

Match::Match()
{

}

void Match::start()
{
	init();

	cout << endl << "Spielstart:" << endl;

	for (int minute = 1; minute <= 90; minute++)
	{
		cout << "Minute " << minute << ": " << endl;
		nextMinute();
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
	vector<Player> players = vector<Player>();

	for (auto player : teamA)
	{
		players.push_back(player);
	}
	for (auto player : teamB)
	{
		players.push_back(player);
	}

	std::random_shuffle(players.begin(), players.end());

	for (auto player : players)
	{
		player.performRound();
	}
}
