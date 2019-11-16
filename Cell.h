#ifndef CELL_H
#define CELL_H

class Cell
{
public:
	
	enum class State : bool {
		INACTIVE = 0,					//!< État inactif, mort, noir, 0, ...
		ACTIVE = 1,						//!< État actif, vivant, blanc, 1, ...
	};

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
	//! \brief Accesseur de l'état
	//////////////////////////////////////////////////////////////////////////
	State state() const; //ou pas const?
    
	void setState(State state);

	void randomize(double probability = 0.5);

    
	//Necessaire ou non?

    //Effectue la conversion entre un état et un caractère.
	//char toChar() const;

	//static void setRepresentation(char inactive, char active);


};




#endif // CELL_H
