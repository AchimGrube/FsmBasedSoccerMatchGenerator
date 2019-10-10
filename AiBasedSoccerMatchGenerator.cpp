#pragma once

#include <ctime>
#include <iostream>
#include "Match.h"

int main()
{
	srand((unsigned)std::time(NULL));

	Match match = Match();
	match.start();

	return 0;
}