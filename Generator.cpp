#pragma once

#include <fstream>

#include "Generator.h"
#include "Player.h"
#include "Position.h"
#include "Pitch.h"

Generator::Generator()
{
}

Generator::~Generator()
{
}

Player Generator::getNewPlayer()
{
	Player newPlayer(getName());
	newPlayer.setPosition(rand() % Pitch::SIZE_X, rand() % Pitch::SIZE_Y);
	newPlayer.setLevel((rand() % 5) + 1);

	return newPlayer;
}

std::string Generator::getName()
{
	if (names.size() == 0)
	{
		std::ifstream file;
		std::string line;

		file.open("vornamen.csv");

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

	std::string newName = names.at(rndEntry) + " ";
	newName += rand() % ('Z' - 'A' + 1) + 'A';
	newName += ".";

	return newName;
}