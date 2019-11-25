#ifndef MODEL_H 
#define	MODEL_H

#include "Space.hpp"
#include "Rule.hpp"
#include "SpaceSample.hpp"
#include "Cell.hpp"

class Model {

public:
	Model() = delete;
	Model(int width, int height);
	~Model() = default;

	//mettre a jour l'espace 

	void updateSpace();
	Space& space1();
	Space& space2();

private:
	//vector<Rule> mRule;
	Space* mSpace1 = nullptr;
	Space* mSpace2 = nullptr;
	Rule regle1{ Rule("123", "456") };

};

#endif	//MODEL_H
