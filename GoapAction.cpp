//#include "GoapAction.h"
//
//std::unordered_set<pair<string, bool>> GoapAction::getPreconditions()
//{
//	return preconditions;
//}
//
//std::unordered_set<pair<string, bool>> GoapAction::getEffects()
//{
//	return effects;
//}
//
//void GoapAction::addPrecondition(pair<string, bool> kvp)
//{
//	preconditions.emplace(kvp);
//}
//
//void GoapAction::removePrecondition(string key)
//{
//	pair<string, bool> remove;
//
//	for (auto element : preconditions)
//	{
//		if (element.first == key)
//		{
//			remove = element;
//		}
//	}
//
//	preconditions.erase(remove);
//}
//
//void GoapAction::addEffect(pair<string, bool> kvp)
//{
//	effects.emplace(kvp);
//}
//
//void GoapAction::removeEffect(string key)
//{
//
//}