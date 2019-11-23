#ifndef RULE_H
#define RULE_H

#include <string>
#include <vector>
#include "Cell.h"

using namespace std;

class Rule {

public:
	//naviguer de regle en regle
	void nextRule();
	void prevRule();

	string getRule();

	//regles (temporaire)
	vector<string> mRules{ "B3/S23", "B36/S23", "B3678/S34678"};


private:

	//constructeur et destructeur
	Rule() = default;
	~Rule() = default;

	//permet de naviguer entre les regles
	vector<string>::iterator mIt = mRules.begin();

	//Separer les vivants des morts a partir des regles
	vector<int> mRuleAlive;
	vector<int> mRuleDead;

	//permet de vérifier le prochain etat de la cellule selon son voisinage
	bool stateOutcome(int nbAlive, Cell state);

};

#endif //RULE_H
