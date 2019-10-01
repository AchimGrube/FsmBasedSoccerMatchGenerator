#include "Match.h"

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
		for (auto item : teamA)
		{
			
		}
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