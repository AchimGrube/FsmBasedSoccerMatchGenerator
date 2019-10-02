#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>
#include <Windows.h>
#include <array>

#include "Pitch.h"
#include "Player.h"
#include "Ball.h"
#include "NameGenerator.h"

using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::array;

class Match
{

public:

	Match();
	
	Ball* getBall();

	int getLength() const;

	int getMinute() const;
	void addMinute();

	pair<int, int> getScore() const;
	void setScore(int, int);

	bool hasEnded() const;

	void start();

private:

	array<Player, 2> teamA;
	//Player teamA[1];
	array<Player, 2> teamB;
	//Player teamB[1];

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