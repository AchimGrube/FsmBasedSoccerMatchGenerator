#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>
#include <Windows.h>
#include <array>
#include <memory>

#include "Pitch.h"
#include "Player.h"
#include "Ball.h"
#include "Generator.h"

using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::array;

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

	void start();


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

	static pair<int, int> score;
};