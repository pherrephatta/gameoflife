#ifndef RULE_H
#define RULE_H

#include <string>
#include <vector>
#include "Cell.h"


class Rule {
	
public:
	//constructeur et destructeur
	Rule() = default;
	~Rule() = default;

	//naviguer de regle en regle
	void nextRule();
	void prevRule();

	
private:

	//Separer les vivants des morts a partir des regles
	std::vector<int> mRuleAlive;
	std::vector<int> mRuleDead;

	//permet de vérifier le prochain etat de la cellule selon son voisinage
	bool stateOutcome(int nbAlive, Cell state);

};

#endif //RULE_H
