#include "Model.hpp"


	/*
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
	*/

	Model::Model(int width, int height) {
		mSpace1 = new Space(width, height);
		mSpace2 = new Space(*mSpace1);
	}

	Space& Model::space1(){return *mSpace1;}
	Space& Model::space2(){return *mSpace2;}

	void Model::updateSpace() {

	}
