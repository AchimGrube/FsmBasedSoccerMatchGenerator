#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <ctime>

#include "Player.h"
#include "Position.h"
#include "Pitch.h"

using std::string;
using std::vector;

class Generator
{
public:

	Player getNewPlayer();

private:

	vector<string> names;
	string getName();

};