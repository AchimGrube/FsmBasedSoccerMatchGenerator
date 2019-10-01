#include <iostream>
#include <Windows.h>

#include "Match.h"

using std::cout;
using std::endl;

void drawOnConsole(int, int, bool);

int main()
{
	Match::start();

	return 0;
}

void drawOnConsole(int x, int y, bool clearLine)
{
	COORD coord;
	coord.Y = y;

	if (clearLine)
	{
		for (int i = 0; i < 121; i++)
		{
			coord.X = i;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
			cout << " ";
		}
	}

	coord.X = x;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}