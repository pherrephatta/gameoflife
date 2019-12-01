#include "SpaceSample.hpp"
#include <iostream>

SpaceSample::SpaceSample(std::vector<std::vector<Cell>>::const_iterator stateIt)
	: mStateIt{ stateIt }
{
}

void SpaceSample::setIterateurs(std::vector<Cell>::const_iterator it) { //update iterators as the facade moves in the vector
	int dist = std::distance(mStateIt->begin(), it);

	mStateIt_center = mStateIt->begin();
	mStateIt_bas = mStateIt->begin(); 
	mStateIt_haut = mStateIt->begin();
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
	nbNeighbors += (int)(left(mStateIt_haut)).state();
	nbNeighbors += (int)(right(mStateIt_haut)).state();
	nbNeighbors += (int)(center(mStateIt_haut)).state();
}

void SpaceSample::middle() {
	nbNeighbors += (int)(left(mStateIt_center)).state();
	nbNeighbors += (int)(right(mStateIt_center)).state();
}

void SpaceSample::down() {
	nbNeighbors += (int)(left(mStateIt_bas)).state();
	nbNeighbors += (int)(right(mStateIt_bas)).state();
	nbNeighbors += (int)(center(mStateIt_bas)).state();
}


Cell const & SpaceSample::right(std::vector<Cell>::const_iterator it) const {

	return *std::next(it);
}

Cell const & SpaceSample::left(std::vector<Cell>::const_iterator it) const {
	return *std::prev(it);
}
