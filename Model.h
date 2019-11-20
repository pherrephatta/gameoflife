#ifndef MODEL_H 
#define	MODEL_H

#include "Space.h"
#include "Rule.h"

class Model {

public:
	Model()		= default;
	~Model()	= default;

	//mettre a jour l'espace 
	void updateSpace();

	//initialiser l'espace
	void initSpace();
	   	  
private:

	vector<Rule> mRule;
	Space* mSpace1;
	Space* mspace2;


};

#endif	//MODEL_H