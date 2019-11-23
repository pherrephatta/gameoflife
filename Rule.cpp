#include "Rule.h"

//next et previous rules
void Rule::nextRule() {
	mIt == mRules.end()-1 ? mIt = mRules.begin() : ++mIt;
}

void Rule::prevRule() {
	mIt == mRules.begin() ? mIt = mRules.end()-1 : --mIt;
}

//permet de vérifier le prochain etat de la cellule selon son voisinage
bool Rule::stateOutcome(int nbAlive, Cell state) {
	return false;
}

string Rule::getRule() {
	return *mIt;
}