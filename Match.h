#pragma once

#include <list>
#include <string>
#include <array>
#include <vector>
#include <iostream>
#include <memory>

#include "Player.h"
#include "Ball.h"
#include "Pitch.h"

enum class TextSpeed
{
	Instant = 0, Fast = 250, Normal = 500, Slow = 1000
};

class Match
{
public:

	Match();
	~Match();

	std::shared_ptr<Ball> getBall();
	std::shared_ptr<Pitch> getPitch();

	int getLength() const;

	int getMinute() const;
	void addMinute();

	bool hasEnded() const;

	void addGoalTeamA();
	void addGoalTeamB();
	void resetScore();

	std::list<std::string> getTextOutput();
	void addTextOutput(std::string);

	void start();

	static int textSpeed;

private:

	std::array<Player, 10> teamA;
	std::array<Player, 10> teamB;

	std::vector<Player*> players;

	std::shared_ptr<Pitch> pitch;
	std::shared_ptr<Ball> ball;

	int length;
	int minute;

	std::pair<int, int> score;

	std::list<std::string> textOutput;

	void init();
	void nextMinute();
	void saveOutput();
};