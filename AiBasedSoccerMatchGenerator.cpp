#pragma once

#include <iostream>

#include "Match.h"

using std::cout;
using std::endl;

int main()
{
	Match* match = new Match();
	match->start();

	return 0;
}