#include "SpaceSample.hpp"
#include <iostream>

SpaceSample::SpaceSample(Space *space)
	: mSpace( space)
{
}

int SpaceSample::GetNeighbors(int y, int x) {
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
	int y_up = this->y > 0 ? y - 1 : mSpace->Height() - 1;
	nbNeighbors += (int)(left(y_up).state());
	nbNeighbors += (int)(right(y_up).state());
	nbNeighbors += (int)(center(y_up).state());
}

void SpaceSample::middle() {
	nbNeighbors += (int)(left(y).state());
	nbNeighbors += (int)(right(y).state());
}

void SpaceSample::down() {
	int y_down = this->y == mSpace->Height() - 1 ? 0 : y + 1;
	nbNeighbors += (int)(left(y_down).state());
	nbNeighbors += (int)(right(y_down).state());
	nbNeighbors += (int)(center(y_down).state());
}

Cell const & SpaceSample::right(int y) const {
	return ((x >= (mSpace->Length() - 1)) ? mSpace->getSpace()[y][0] : mSpace->getSpace()[y][x + 1]);
}

Cell const & SpaceSample::left(int y) const {
	return ((x <= 0) ? mSpace->getSpace()[y][(mSpace->Length()) - 1] : mSpace->getSpace()[y][x - 1]);
}

Cell const & SpaceSample::center(int y) const {
	return mSpace->getSpace()[y][x];
}
