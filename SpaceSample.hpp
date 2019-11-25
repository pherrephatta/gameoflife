#ifndef SPACESAMPLE_H
#define SPACESAMPLE_H

#include  "Cell.hpp"
#include <vector>

class SpaceSample
{
public:


	//Constructeurs
	SpaceSample() = default;
	SpaceSample(std::vector<Cell> const & space, std::vector<Cell>::const_iterator stateIt, int largeur);









	//Destructeurs
	~SpaceSample() = default;

	//////////////////////////////////////////////////////////////////////////
	//! \brief Accesseur de l'état
	//////////////////////////////////////////////////////////////////////////




	int GetNeighbors(std::vector<Cell>::const_iterator it);

	Cell const & left(std::vector<Cell>::const_iterator it) const;
	Cell const & right(std::vector<Cell>::const_iterator it) const;
	Cell const & center(std::vector<Cell>::const_iterator it) const;
	void up();
	void middle();
	void down();
	void setIterateurs(std::vector<Cell>::const_iterator it);



private:



	std::vector<Cell> const & mSpace;
	std::vector<Cell>::const_iterator mStateIt;
	std::vector<Cell>::const_iterator mStateIt_haut;
	std::vector<Cell>::const_iterator mStateIt_bas;
	int mLargeur;
	int nbNeighbors = 0;

};










#endif // SPACESAMPLE_H
