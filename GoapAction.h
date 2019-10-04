//#pragma once
//
//#include <unordered_set>
//#include <string>
//#include "Player.h"
//
//using std::string;
//using std::pair;
//
//class GoapAction abstract
//{
//
//public:
//
//	virtual std::unordered_set<pair<string, bool>> getPreconditions();
//	virtual std::unordered_set<pair<string, bool>> getEffects();
//
//	virtual bool isDone() = 0;
//	virtual bool perform(Player) = 0;
//
//	virtual void addPrecondition(pair<string, bool>);
//	virtual void removePrecondition(string);
//	virtual void addEffect(pair<string, bool>);
//	virtual void removeEffect(string);
//
//private:
//
//	std::unordered_set<pair<string, bool>> preconditions;
//	std::unordered_set<pair<string, bool>> effects;
//
//	int cost;
//};