#ifndef SPACE_H
#define SPACE_H

#include <Vector>
#include "Cell.h"

class Space
{
public:
	
	

    private: 

    std::vector<Cell> mSpace;
    int m_lenght;
    int m_height;

    
    //Color mColor; CLASSE COULEUR A IMPLANTER 

    public: 
    //Constructeurs
	Space() = default;
    Space(std::vector<Cell> v, int lenght, int height);


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
