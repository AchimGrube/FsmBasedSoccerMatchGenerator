#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

#include "Pitch.h"
#include "Player.h"
#include "Ball.h"
#include "NameGenerator.h"

using std::cout;
using std::endl;
using std::vector;
using std::pair;

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

	Player teamA[1];
	Player teamB[1];

	Pitch pitch;
	Ball ball;

	int length, minute;
	pair<int, int> score;
	
	void init(); 
	void nextMinute();
};

