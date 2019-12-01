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
	size_t GetNeighbors(size_t y, size_t x);
	size_t x;
	size_t y;

private:
	size_t nbNeighbors{};
	void up();
	void middle();
	void down();
	Cell const & left(size_t y) const;
	Cell const & right(size_t y) const;
	Cell const & center(size_t y) const;
};

#endif // SPACESAMPLE_H