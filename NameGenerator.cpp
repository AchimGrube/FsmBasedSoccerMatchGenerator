#include "NameGenerator.h"

string NameGenerator::getName()
{
	if (names == nullptr)
	{
		names = new vector<string>();

		std::ifstream file;
		string line;

		file.open("vornamen.csv", std::ios::in);

		if (file)
		{
			while (!file.eof())
			{
				std::getline(file, line);

				if (line.length() > 0)
				{
					if (line.substr(line.find_last_of(",") + 1) == "m")
					{
						names->push_back(line.substr(0, line.find_first_of(",")));
					}
				}
			}
		}
	}

	int rndEntry = rand() % names->size();

	string newName = names->at(rndEntry) + " ";
	newName += rand() % ('Z' - 'A' + 1) + 'A';
	newName += ".";

	return newName;
}