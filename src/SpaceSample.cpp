#include "SpaceSample.hpp"
#include <iostream>

SpaceSample::SpaceSample(std::vector <Cell> const & space, std::vector<Cell>::const_iterator stateIt, int largeur)
	: mSpace{ space }, mStateIt{ stateIt }, mLargeur{ largeur }
{ //thoses iterators will be updated in up() and down()
	mStateIt_haut = mStateIt; 
	mStateIt_bas = mStateIt;

}



int SpaceSample::GetNeighbors(std::vector<Cell>::const_iterator it) {
	nbNeighbors = 0;
	setIterateurs(it);
	up();
	middle();
	down();
	return nbNeighbors;
	//std::cout << "nb de voisins : " << calculateNeighborhood() << std::endl;
}

Cell const & SpaceSample::center(std::vector<Cell>::const_iterator it) const {
	return *it;
}

void SpaceSample::up() {

	if ((int)(mStateIt - mSpace.begin()) < mLargeur) { // if first row
		mStateIt_haut = (mSpace.end() - mLargeur + (mStateIt - mSpace.begin()));
	}
	else mStateIt_haut = (mStateIt - mLargeur);

	nbNeighbors += (int)(left(mStateIt_haut)).state();
	nbNeighbors += (int)(right(mStateIt_haut)).state();
	nbNeighbors += (int)(center(mStateIt_haut)).state();
}

void SpaceSample::middle() {
	nbNeighbors += (int)(left(mStateIt)).state();
	nbNeighbors += (int)(right(mStateIt)).state();
}

void SpaceSample::down() {
	if (int(mStateIt - mSpace.begin()) >= int(mSpace.size() - mLargeur)) {// if last row
		mStateIt_bas = (mSpace.begin() + ((mStateIt - mSpace.begin()) % mLargeur));
	} else {
		mStateIt_bas = (mStateIt + mLargeur);
	}

	nbNeighbors += (int)(left(mStateIt_bas)).state();
	nbNeighbors += (int)(right(mStateIt_bas)).state();
	nbNeighbors += (int)(center(mStateIt_bas)).state();
}

void SpaceSample::setIterateurs(std::vector<Cell>::const_iterator it) { //update iterators as the facade moves in the vector
	mStateIt = it;
	mStateIt_bas = it;
	mStateIt_haut = it;
}


Cell const & SpaceSample::right(std::vector<Cell>::const_iterator it) const {
	if (it == mSpace.end() - 1) { // if last cell
		return  *(it - mLargeur + 1);
	}
	else if (it - mSpace.begin() == (mLargeur - 1)) { // if up-right corner
		return  *(it + 1 - mLargeur);
	}
	else if ((((it - mSpace.begin()) + 1) % (mLargeur)) == 0) {  // if last column
		return *(it - mLargeur + 1);
	}
	else {
		return *std::next(it);
	}
}

Cell const & SpaceSample::left(std::vector<Cell>::const_iterator it) const {
	if (it == mSpace.begin()) { // if first cell
		return  *(it + mLargeur - 1);
	} 
	else if ((it - mSpace.begin()) % mLargeur == 0) { // if first column
		return  *(it + (mLargeur - 1));
	} else {
		return *std::prev(it);
	}
}
