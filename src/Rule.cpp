#include "Rule.hpp"
#include <iostream>

Rule::Rule(unsigned char rB, unsigned char rS) {
	mRuleB = rB;
	mRuleS = rS;
}

Rule::Rule(string rB, string rS) 
	:mRuleB{ 0 }, mRuleS{0} {
	//the idea is to convert strings (cont. digits only) in UC rules. the process takes care of possible digit repetition in the rule (ex:2323)
	for (char c : rB) {
		size_t bitToSet = c - '0';
		mRuleB ^= (1 << (bitToSet - 1));
	}
	for (char c : rS) {
		size_t bitToSet = c - '0';
		mRuleS ^= (1 << (bitToSet - 1));
	}
}

bool Rule::outcome(bool state, size_t NbOfNeighbours) {
	return ((state?mRuleS:mRuleB)&(1 << (NbOfNeighbours-1)));
}