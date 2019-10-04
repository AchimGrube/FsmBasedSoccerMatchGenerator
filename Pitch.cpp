#include "Pitch.h"

Pitch::Pitch()
{
	for (int x = 0; x < sizeX; x++)
	{
		for (int y = 0; y < sizeY; y++)
		{
			//tiles[x][y] = Tile(x, y);
			tiles.at(x).at(y) = Tile(x, y);

			if ((x == 0 && y == 5) || (x == 16 && y == 5))
			{
				//tiles[x][y].setArea(Area::Goal);
				tiles.at(x).at(y).setArea(Area::Goal);
			}
			else if (x == 0 || x == 16 || y == 0 || y == 10)
			{
				//tiles[x][y].setArea(Area::Out);
				tiles.at(x).at(y).setArea(Area::Out);
			}
			else if ((x == 1 || x == 2 || x == 14 || x == 15) && y >= 3 && y <= 7)
			{
				//tiles[x][y].setArea(Area::Penalty);
				tiles.at(x).at(y).setArea(Area::Penalty);
			}
			else if (x >= 1 && x <= 15 && (y == 1 || y == 2 || y == 8 || y == 9))
			{
				//tiles[x][y].setArea(Area::Wing);
				tiles.at(x).at(y).setArea(Area::Wing);
			}
			else if (((x >= 3 && x <= 7) || (x >= 9 && x <= 13)) && y >= 3 && y <= 7)
			{
				//tiles[x][y].setArea(Area::Center);
				tiles.at(x).at(y).setArea(Area::Center);
			}
		}
	}
}

std::unique_ptr<Tile> Pitch::getTile(int x, int y)
{
	return std::make_unique<Tile>(tiles.at(x).at(y));
}
