#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class Player;

class Generator
{
public:

	Generator();
	~Generator();

	Player getNewPlayer();

private:

	std::vector<std::string> names;
	std::string getName();
};