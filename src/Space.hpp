#ifndef SPACE_H
#define SPACE_H

#include <vector>
#include <string>
#include "Cell.hpp"

class Space
{
private:

	std::vector<Cell> mSpace;
	int mLenght;
	int mHeight;
	bool mBordersAlive = true;


	//Color mColor; CLASSE COULEUR A IMPLANTER 

public:
	//Constructeurs
	Space() = default;
	Space(int lenght, int height);


	//Destructeurs
	~Space() = default;

	//////////////////////////////////////////////////////////////////////////
	//! \brief Accesseur de l'état
	//////////////////////////////////////////////////////////////////////////
	std::vector<Cell> & getSpace(); //ou pas const?

	void setSpace();

	void setBorders();

	void BordersAlive();

	void wipeSpace();

	void randomize(double probability = 0.5);

	int Lenght() {
		return mLenght;
	};

	int Height() {
		return mHeight;
	}

	void GenFromRLE(std::string s);





	//Necessaire ou non?

	//Effectue la conversion entre un état et un caractère.
	//char toChar() const;

	//static void setRepresentation(char inactive, char active);


};




#endif // SPACE_H
