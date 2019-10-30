#pragma once

#include "Generator.h"
#include "Player.h"
#include "Position.h"
#include "Pitch.h"

// Spielergenerator

Generator::Generator()
{
}

Generator::~Generator()
{
}

// Liefert ein neues Objekt der Klasse <Player> mit zufälligem Namen und Level zurück
Player Generator::getNewPlayer()
{
	Player newPlayer(getName());
	newPlayer.setPosition(rand() % Pitch::SIZE_X, rand() % Pitch::SIZE_Y);
	newPlayer.setLevel((rand() % 5) + 1);

	return newPlayer;
}

// Liest die Datei "vornamen.csv" ein, sofern noch nicht geschehen, und gibt einen zufälligen Männernamen daraus zurück, an den ein zufälliger Großbuchstabe angehängt wird
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
		else
		{
			std::cout << "Datei 'vornamen.csv' nicht gefunden.";
		}
	}

	int rndEntry = rand() % names.size();

	std::string newName = names.at(rndEntry) + " ";
	newName += rand() % ('Z' - 'A' + 1) + 'A';
	newName += ".";

	return newName;
}