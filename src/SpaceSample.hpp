#ifndef SPACESAMPLE_H
#define SPACESAMPLE_H

#include  "Cell.hpp"
#include "Space.hpp"
#include <vector>

class SpaceSample
{
public:
	//Constructeurs
	SpaceSample() = delete;
<<<<<<< HEAD
	SpaceSample(std::vector<Cell> const & space, std::vector<Cell>::const_iterator stateIt, int largeur);
=======
	SpaceSample(Space *space);
>>>>>>> ferat
	//Destructeurs
	~SpaceSample() = default;
	Space *mSpace;

	//////////////////////////////////////////////////////////////////////////
	//! \brief Accesseur de l'état
	//////////////////////////////////////////////////////////////////////////
<<<<<<< HEAD
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

=======
	int GetNeighbors(int y, int x);
	int x;
	int y;

private:
	int nbNeighbors = 0;
	void up();
	void middle();
	void down();
	Cell const & left(int y) const;
	Cell const & right(int y) const;
	Cell const & center(int y) const;
>>>>>>> ferat
};

#endif // SPACESAMPLE_H
