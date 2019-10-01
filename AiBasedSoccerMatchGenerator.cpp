#include <iostream>

#include "Player.h"
#include "NameGenerator.h"
#include "_functions.h"
#include "Pitch.h"

using std::cout;
using std::endl;

int main()
{
	Pitch* p = new Pitch();

	Player* teamA[10];
	Player* teamB[10];

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

	for (auto e : teamA)
	{
		cout << e->getName() << " zu Team A hinzugefuegt." <<  endl;
	}

	for (auto e : teamB)
	{
		cout << e->getName() << " zu Team B hinzugefuegt." << endl;
	}
}