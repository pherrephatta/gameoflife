#ifndef SPACE_H
#define SPACE_H

#include <vector>
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
	std::vector<Cell>const & getSpace() const; //ou pas const?
    
	void setSpace();

	void setBorders();

	void BordersAlive(bool b);

	void randomize(double probability = 0.5);

	int Lenght() {
		return mLenght;
	};


    
	//Necessaire ou non?

    //Effectue la conversion entre un état et un caractère.
	//char toChar() const;

	//static void setRepresentation(char inactive, char active);


};




#endif // SPACE_H
