#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

#include "Pitch.h"
#include "Player.h"
#include "NameGenerator.h"

using std::cout;
using std::endl;
using std::vector;

class Match
{

public:

	Match();

	void start();

private:

	Player teamA[1];
	Player teamB[1];

	Pitch pitch;

	void init(); 
	void nextMinute();
};

