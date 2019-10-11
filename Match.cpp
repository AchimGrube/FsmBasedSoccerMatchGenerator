#pragma once

#include "Match.h"
#include "Position.h"
#include "_functions.h"
#include "Generator.h"

int Match::textSpeed;

// Initialisiert und steuert den eigentlichen Spielablauf (die Anzahl der Spieler wird in der Datei <Match.h> voreingestellt)
Match::Match()
{
	this->length = 90;
	this->minute = 1;
	this->ball = std::make_shared<Ball>();
	this->ball->setPosition(8, 5);
	this->pitch = std::make_shared<Pitch>();
}

Match::~Match()
{
}

std::shared_ptr<Ball> Match::getBall()
{
	return std::shared_ptr<Ball>(this->ball);
}

std::shared_ptr<Pitch> Match::getPitch()
{
	return std::shared_ptr<Pitch>(this->pitch);
}

int Match::getLength() const
{
	return this->length;
}

int Match::getMinute() const
{
	return this->minute;
}

void Match::addMinute()
{
	this->minute++;
}

bool Match::hasEnded() const
{
	return this->minute > this->length;
}

void Match::addGoalTeamA()
{
	this->score.first++;
}

void Match::addGoalTeamB()
{
	this->score.second++;
}

void Match::resetScore()
{
	this->score.first = 0;
	this->score.second = 0;
}

std::list<std::string> Match::getTextOutput()
{
	return textOutput;
}

void Match::addTextOutput(std::string text)
{
	textOutput.push_back(text);
}

void Match::start()
{
	init();

	processText("*** ANPFIFF ***\n\n", *this);

	while (!hasEnded())
	{
		char buffer[32];
		snprintf(buffer, 32, "### Minute %02d   [%d:%d] ###\n\n", minute, score.first, score.second);
		processText(buffer, *this);

		nextMinute();
	}

	processText("*** ABPFIFF ***\n", *this);

	processText("\n\n-->> Das Spiel endete " + std::to_string(score.first) + ":" + std::to_string(score.second) + "\n\n\n", *this);

	saveOutput();
}

// Setzt das Ergebnis zurück, stellt die Geschwindigkeit des Ablaufs ein und erstellt die beiden Mannschaften sowie einen Vector aller Spieler
void Match::init()
{
	resetScore();

	this->textSpeed = (int)TextSpeed::Slow;

	this->textOutput.clear();

	Generator generator;
	
	Position teamAGoal = Position(0, 5);
	Position teamBGoal = Position(16, 5);

	for (size_t i = 0; i < teamA.size(); i++)
	{
		teamA.at(i) = generator.getNewPlayer();
		teamA.at(i).setOpponentGoalPosition(teamBGoal);
		players.push_back(&teamA.at(i));
	}
	for (size_t i = 0; i < teamB.size(); i++)
	{
		teamB.at(i) = generator.getNewPlayer();
		teamB.at(i).setOpponentGoalPosition(teamAGoal);
		players.push_back(&teamB.at(i));
	}
}

// Mischt die Spielerliste neu und führt für jeden Spieler eine Aktion pro "Minute" durch
void Match::nextMinute()
{
	std::random_shuffle(players.begin(), players.end());

	for (auto& player : players)
	{
		player->performRound(*this);
	}

	addMinute();

	pause(this->textSpeed);
}

// Möglichkeit, die Textausgabe in eine Datei zu schreiben
void Match::saveOutput()
{
	std::cout << "Soll das Ergebnis in einer Datei gespeichert werden?\n";

	std::string input = "";

	while (input == "")
	{
		std::cout << "[J/N] ";
		std::cin >> input;

		if (input == "j" || input == "J")
		{
			writeToFile(getTextOutput());
			break;
		}
		else if(input == "n" || input == "N")
		{
			break;
		}
		else
		{
			input = "";
		}
	}
}