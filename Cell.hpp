#ifndef CELL_H
#define CELL_H

#include "RandomUtil.hpp"

enum class State : bool {
	INACTIVE = 0,					//!< État inactif, mort, noir, 0, ...
	ACTIVE = 1,						//!< État actif, vivant, blanc, 1, ...
};


class Cell
{
public:
	

    private: 

    State mState;
    
    //Color mColor; CLASSE COULEUR A IMPLANTER 

    public: 
    //Constructeurs
	Cell() = default;
    Cell(State state);


    //Destructeurs
	~Cell() = default;

	//////////////////////////////////////////////////////////////////////////
	// Accesseur de l'état
	//////////////////////////////////////////////////////////////////////////
	State state() const; //ou pas const?


    
	void setState(State state);

	void randomize(double probability = 0.5);

    

};




#endif // CELL_H
