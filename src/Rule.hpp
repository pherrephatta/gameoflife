#ifndef RULE_H
#define RULE_H

#include <string>
#include <vector>
#include <cassert>
#include "Cell.hpp"

using namespace std;

class Rule {
	unsigned char mRuleB; //rules are expressed as 8 bits values. ex: if for birth 2 or 4 alive neighbours are necessary. the UC representing such rule is 0000 1010.
	unsigned char mRuleS; //
	

public:
	//constructeur et destructeur
	Rule(unsigned char rB, unsigned char rS); //ctor used when reading from RLE file
	Rule(string rB, string rS);
	~Rule() = default;
	unsigned char ruleB() { return mRuleB; }
	unsigned char ruleS() { return mRuleS; }
	bool outcome(bool state, int NbOfNeighbours);
};

#endif //RULE_H
