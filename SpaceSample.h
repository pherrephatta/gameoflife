#ifndef SPACESAMPLE_H
#define SPACESAMPLE_H

#include  "Cell.h"
#include <vector>

class SpaceSample
{
public:
	

    //Constructeurs
	SpaceSample() = default;
	SpaceSample(std::vector<Cell> const & space, std::vector<Cell>::const_iterator stateIt);
	





	void setStateIt(std::vector<Cell>::const_iterator stateIt);


    //Destructeurs
	~SpaceSample() = default;

	//////////////////////////////////////////////////////////////////////////
	//! \brief Accesseur de l'état
	//////////////////////////////////////////////////////////////////////////

    
	std::vector<State> Neighborhood();



	int calculateNeighborhood();

	void GetNeighbors(std::vector<Cell>::const_iterator it_qui_bouge,  int largeur);

	Cell const & left() const;
	Cell const & right() const;
	Cell const & center() const;
	Cell const & up(int largeur);
	Cell const & down(int largeur) ;

	
private:


	std::vector<Cell> mNeighborhood;
	bool mBorderMngnt;
	std::vector<Cell> const & mSpace;
	std::vector<Cell>::const_iterator mStateIt;
};


    
	






#endif // SPACESAMPLE_H
