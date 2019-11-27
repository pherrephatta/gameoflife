#ifndef MODEL_H 
#define	MODEL_H

#include "Space.hpp"
#include "Rule.hpp"
#include "SpaceSample.hpp"
#include "Cell.hpp"
#include <iostream>

class Model {

public:
	Model() = delete;
	Model(int width, int height);
	~Model() = default;

	//mettre a jour l'espace 

	void updateSpace();
	Space& space1();
	Space& space2();
	unsigned int indexRule() { return mIndexRule; };
	void nextRule();

private:
	//vector<Rule> mRule;
	Space* mSpace1 = nullptr;
	Space* mSpace2 = nullptr;
	Rule regle1{ Rule("123", "456") };
	std::vector<Rule> mRules{ Rule("3", "23"), Rule("36", "23") , Rule("3678", "34678"), Rule("1", "7") };
	
	unsigned int mIndexRule{ 0 };
};

#endif	//MODEL_H
