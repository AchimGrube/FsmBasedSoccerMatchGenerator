#pragma once

class Entity abstract
{
public:

	int getPosX() { return posX; };
	void setPosX(int x) { this->posX = x; };

	int getPosY() { return posY; };
	void setPosY(int y) { this->posY = y; };

	virtual void moveTo(int x, int y);

private:

	int posX = 0, posY = 0;
};