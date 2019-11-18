#ifndef SPACE_H
#define SPACE_H

#include <Vector>
#include "Cell.h"

class Space
{

    private: 

    std::vector<Cell> mSpace;
    int mLenght;
    int mHeight;

    
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
	std::vector<Cell> getSpace() const; //ou pas const?
    
	void setSpace();

	void randomize(double probability = 0.5);

    
	//Necessaire ou non?

    //Effectue la conversion entre un état et un caractère.
	//char toChar() const;

	//static void setRepresentation(char inactive, char active);


};




#endif // SPACE_H
