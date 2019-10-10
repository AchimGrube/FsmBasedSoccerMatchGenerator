#pragma once

#include <vector>
#include <string>

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