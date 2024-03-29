#pragma once

#include <string>
#include <memory>

#include "Entity.h"
#include "Position.h"

enum class State;
class Pitch;
class Ball;
class PlayerState;
class Match;
class FiniteStateMachine;

class Player : public Entity
{
public:

	Player();
	Player(std::string);
	~Player();

	std::string getName() const;

	std::string getTeam() const;
	void setTeam(std::string);

	int getLevel() const;
	void setLevel(int);

	State getState() const;
	void setState(const State&);

	bool hasBall() const;
	void hasBall(bool);

	std::shared_ptr<Position> getTarget();
	void setTarget(Position&);

	std::shared_ptr<Position> getOpponentGoalPosition();
	void setOpponentGoalPosition(Position&);

	void performRound(Match&);

private:

	std::string name;
	std::string team;
	int level;
	State state;
	bool playerHasBall;
	std::shared_ptr<Position> target;
	std::shared_ptr<Position> opponentGoalPosition;

	std::shared_ptr<PlayerState> _playerState;
	std::shared_ptr<FiniteStateMachine> _fsm;
};