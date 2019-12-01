#include "SpaceSample.hpp"
#include <iostream>

SpaceSample::SpaceSample(Space *space)
	: mSpace( space)
{
}

size_t SpaceSample::GetNeighbors(size_t y, size_t x) {
	this->x = x;
	this->y = y;
	nbNeighbors = 0;
	up();
	middle();
	down();
	return nbNeighbors;
	//std::cout << "nb de voisins : " << calculateNeighborhood() << std::endl;
}

void SpaceSample::up() {
	size_t y_up = this->y > 0 ? y - 1 : mSpace->Height() - 1;
	nbNeighbors += (size_t)(left(y_up).state());
	nbNeighbors += (size_t)(right(y_up).state());
	nbNeighbors += (size_t)(center(y_up).state());
}

void SpaceSample::middle() {
	nbNeighbors += (size_t)(left(y).state());
	nbNeighbors += (size_t)(right(y).state());
}

void SpaceSample::down() {
	size_t y_down = this->y == mSpace->Height() - 1 ? 0 : y + 1;
	nbNeighbors += (size_t)(left(y_down).state());
	nbNeighbors += (size_t)(right(y_down).state());
	nbNeighbors += (size_t)(center(y_down).state());
}

Cell const & SpaceSample::right(size_t y) const {
	return ((x >= (mSpace->Length() - 1)) ? mSpace->getSpace()[y][0] : mSpace->getSpace()[y][x + 1]);
}

Cell const & SpaceSample::left(size_t y) const {
	return ((x <= 0) ? mSpace->getSpace()[y][(mSpace->Length()) - 1] : mSpace->getSpace()[y][x - 1]);
}

Cell const & SpaceSample::center(size_t y) const {
	return mSpace->getSpace()[y][x];
}