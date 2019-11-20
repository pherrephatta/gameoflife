#ifndef CONTROLLER_H
#define	CONTROLLER_H

#include "Model.h"
//#include "View.h"

class Controller {

public:

	Model model;
	//View view;

	//Constructeur et Destructeur par defaut
	Controller()	= default;
	~Controller()	= default;

	//Constructeur avec Model et View


	//changer vitesse de l'animation
	void changeTime();

private:

	vector<string> mFile;
	array<int> mSpeed{};
	string mPath;
	int mIndexFile{};
	int mIndexSpeed{};

};

#endif //CONTROLLER_H