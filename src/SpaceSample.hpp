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
	SpaceSample(Space *space);
	//Destructeurs
	~SpaceSample() = default;
	Space *mSpace;

	//////////////////////////////////////////////////////////////////////////
	//! \brief Accesseur de l'état
	//////////////////////////////////////////////////////////////////////////
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
};

#endif // SPACESAMPLE_H
