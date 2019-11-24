#ifndef MODEL_H 
#define	MODEL_H

#include "Space.hpp"
#include "Rule.hpp"

class Model {

public:
	Model(int width, int height);
	~Model() = default;

	//mettre a jour l'espace 
	void updateSpace();
	   	  
private:
	//vector<Rule> mRule;
	Space* mSpace1 = nullptr;
	Space* mSpace2 = nullptr;
};

#endif	//MODEL_H
