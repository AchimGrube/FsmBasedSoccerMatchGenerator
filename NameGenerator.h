#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <ctime>

using std::string;
using std::vector;

class NameGenerator
{
public:

	string getName();

private:

	vector<string> names;
};