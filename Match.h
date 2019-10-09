#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>
#include <Windows.h>
#include <array>
#include <memory>
#include <list>
#include <fstream>
#include <ctime>

#include "Pitch.h"
#include "Player.h"
#include "Ball.h"
#include "Generator.h"

using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::array;

enum class TextSpeed
{
	Instant = 0, Fast = 250, Normal = 500, Slow = 1000
};

class Match
{

public:

	Match();

	std::shared_ptr<Ball> getBall();

	int getLength() const;

	int getMinute() const;
	void addMinute();

	bool hasEnded() const;

	static void addGoalTeamA();
	static void addGoalTeamB();
	static void resetScore();

	static std::list<string> getTextOutput();
	static void addTextOutput(string);

	void start();

	static int textSpeed;

private:

	array<Player, 10> teamA;
	array<Player, 10> teamB;

	vector<Player*> players;

	Pitch pitch;
	Ball ball;

	int length, minute;

	void init();
	void nextMinute();
	void printMatchLines(Player&);
	void setConsoleCursorPosition(int, int, bool);
	void saveTextToFile();

	static pair<int, int> score;
	static std::list<string> textOutput;
};