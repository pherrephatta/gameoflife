#include "SpaceSample.hpp"
#include <iostream>

<<<<<<< HEAD
SpaceSample::SpaceSample(std::vector <Cell> const & space, std::vector<Cell>::const_iterator stateIt, int largeur)
	: mSpace{ space }, mStateIt{ stateIt }, mLargeur{ largeur }
{ //thoses iterators will be updated in up() and down()
	mStateIt_haut = mStateIt; 
	mStateIt_bas = mStateIt;
}

int SpaceSample::GetNeighbors(std::vector<Cell>::const_iterator it) {
=======
SpaceSample::SpaceSample(Space *space)
	: mSpace( space)
{
}

int SpaceSample::GetNeighbors(int y, int x) {
	this->x = x;
	this->y = y;
>>>>>>> ferat
	nbNeighbors = 0;
	up();
	middle();
	down();
	return nbNeighbors;
	//std::cout << "nb de voisins : " << calculateNeighborhood() << std::endl;
}

void SpaceSample::up() {
<<<<<<< HEAD
	
	mStateIt_haut = (mStateIt - mLargeur);
	nbNeighbors += (int)(left(mStateIt_haut)).state();
	nbNeighbors += (int)(right(mStateIt_haut)).state();
	nbNeighbors += (int)(center(mStateIt_haut)).state();
=======
	int y_up = this->y > 0 ? y - 1 : mSpace->Height() - 1;
	nbNeighbors += (int)(left(y_up).state());
	nbNeighbors += (int)(right(y_up).state());
	nbNeighbors += (int)(center(y_up).state());
>>>>>>> ferat
}

void SpaceSample::middle() {
	nbNeighbors += (int)(left(y).state());
	nbNeighbors += (int)(right(y).state());
}

void SpaceSample::down() {
<<<<<<< HEAD
	mStateIt_bas = (mStateIt + mLargeur);
	nbNeighbors += (int)(left(mStateIt_bas)).state();
	nbNeighbors += (int)(right(mStateIt_bas)).state();
	nbNeighbors += (int)(center(mStateIt_bas)).state();
=======
	int y_down = this->y == mSpace->Height() - 1 ? 0 : y + 1;
	nbNeighbors += (int)(left(y_down).state());
	nbNeighbors += (int)(right(y_down).state());
	nbNeighbors += (int)(center(y_down).state());
>>>>>>> ferat
}

Cell const & SpaceSample::right(int y) const {
	return ((x >= (mSpace->Length() - 1)) ? mSpace->getSpace()[y][0] : mSpace->getSpace()[y][x + 1]);
}

<<<<<<< HEAD
Cell const & SpaceSample::right(std::vector<Cell>::const_iterator it) const {
	return *std::next(it);
}

Cell const & SpaceSample::left(std::vector<Cell>::const_iterator it) const {
	return *std::prev(it);
=======
Cell const & SpaceSample::left(int y) const {
	return ((x <= 0) ? mSpace->getSpace()[y][(mSpace->Length()) - 1] : mSpace->getSpace()[y][x - 1]);
}

Cell const & SpaceSample::center(int y) const {
	return mSpace->getSpace()[y][x];
>>>>>>> ferat
}
