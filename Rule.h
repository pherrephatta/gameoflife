#ifndef RULE_H
#define RULE_H

#include <string>
#include <vector>
#include "Cell.h"


class Rule {

private:

	//Separer les vivants des morts a partir des regles
	std::vector<int> ruleAlive;
	std::vector<int> ruleDead;

	Rule() = default;
	~Rule() = default;

	//naviguer de regle en regle
	void nextRule(int i);
	void prevRule(int i);

	//
	bool stateOutcome(int nbAlive, Cell state);

};

#endif //RULE_H
