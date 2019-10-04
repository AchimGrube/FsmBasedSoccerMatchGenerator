#include "Generator.h"

Player Generator::getNewPlayer()
{
	Player newPlayer(getName());
	Position startPosition;
	startPosition.set(rand() % Pitch::sizeX, rand() % Pitch::sizeY);
	newPlayer.setPosition(startPosition);
	//
	newPlayer.setPosition(Position(8, 5));
	//
	newPlayer.setLevel((rand() % 5) + 1);
	return newPlayer;
}

string Generator::getName()
{
	if (names.size() == 0)
	{
		std::ifstream file;
		string line;

		file.open("vornamen.csv", std::ios::in);

		if (file)
		{
			while (!file.eof())
			{
				std::getline(file, line);

				if (line.length() > 0)
				{
					if (line.substr(line.find_last_of(",") + 1) == "m")
					{
						names.push_back(line.substr(0, line.find_first_of(",")));
					}
				}
			}
		}
	}

	int rndEntry = rand() % names.size();

	string newName = names.at(rndEntry) + " ";
	newName += rand() % ('Z' - 'A' + 1) + 'A';
	newName += ".";

	return newName;
}