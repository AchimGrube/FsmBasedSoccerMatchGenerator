#include <vector>
#include <algorithm>

#include "Match.h"

using std::vector;

namespace Match
{
	void nextMinute();
	void init();

	Player* teamA[10];
	Player* teamB[10];
	
	Pitch* pitch;

	void start()
	{
		init();

		cout << endl << "Spielstart:" << endl;

		for (int minute = 1; minute <= 90; minute++)
		{
			cout << "Minute " << minute << ": " << endl;
			nextMinute();
		}
	}

	void nextMinute()
	{
		//vector<Player*> players = vector<Player*>();

		//for (auto player : teamA)
		//{
		//	players.push_back(player);
		//}
		//for (auto player : teamB)
		//{
		//	players.push_back(player);
		//}

		//std::shuffle(players.begin(), players.end(), 0);

		//for (auto player : players)
		//{
		//	cout << player->getName() << endl;
		//}
	}

	void init()
	{
		pitch = new Pitch();

		NameGenerator* ng = new NameGenerator();
		srand((unsigned)std::time(NULL));

		for (int i = 0; i < sizeof(teamA) / sizeof(teamA[0]); i++)
		{
			teamA[i] = new Player(ng->getName());
		}

		for (int i = 0; i < sizeof(teamB) / sizeof(teamB[0]); i++)
		{
			teamB[i] = new Player(ng->getName());
		}

		delete ng;
	}
}