#ifndef CONTROLER_H
#define	CONTROLER_H

#include <array>
#include "Model.hpp"
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
	std::array<int, 5> mSpeed{};
	string mPath;
	int mIndexFile{};
	int mIndexSpeed{};

};

#endif //CONTROLER_H
