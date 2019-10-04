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

	pair<int, int> getScore() const;
	void setScore(int, int);

	bool hasEnded() const;

	void start();

private:

	array<Player, 1> teamA;
	array<Player, 1> teamB;

	vector<Player*> players;

	Pitch pitch;
	Ball ball;

	int length, minute;
	pair<int, int> score;
	
	void init(); 
	void nextMinute();
	void printMatchLines(Player&);
	void setConsoleCursorPosition(int, int, bool);
};