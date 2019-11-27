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

bool Rule::outcome(bool state, int NbOfNeighbours) {
	return ((state?mRuleS:mRuleB)&(1 << (NbOfNeighbours-1)));
}

/*
int main() {

	Rule r("111111111112345","678"); //we can create from strings, returned rB and rS will be int224 and int31
	unsigned char testRB = r.ruleB();
	unsigned char testRS = r.ruleS();
	Rule r2(testRB, testRS); //also works with the UC chars
	testRB = r2.ruleB();
	testRS = r2.ruleS();
	cout << "Rules built from UCs :  B" << (int)testRB << "/S" << (int)testRS << endl;

	bool testOutcomeBsuccess = r2.outcome(false, 2); //TRUE
	bool testOutcomeBfail = r2.outcome(false, 7); //FALSE 
	bool testOutcomeS = r2.outcome(true, 2);//TRUE
	bool testOutcomeSfail = r2.outcome(true, 7);//FALSE
}
*/
