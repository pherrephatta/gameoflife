#include "SpaceSample.h"
#include <iostream>



SpaceSample::SpaceSample(std::vector <Cell> const & space, std::vector<Cell>::const_iterator stateIt)
	: mSpace{ space }, mStateIt{ stateIt }
{

}



void SpaceSample::setStateIt(std::vector<Cell>::const_iterator stateIt)
{
	mStateIt = stateIt;

}

std::vector<State> SpaceSample::Neighborhood()
{
	return std::vector<State>();
}

int SpaceSample::calculateNeighborhood()
{
	int nb_of_neighbors{};
	for (int i{}; i < mNeighborhood.size(); ++i)
	{
		nb_of_neighbors += (int)mNeighborhood[i].state();
	}
	return nb_of_neighbors;
}

void SpaceSample::GetNeighbors(std::vector<Cell>::const_iterator stateIt, int largeur)
{
	//mNeighborhood.resize(8);
	setStateIt(stateIt);
	mNeighborhood.push_back(right());
	mNeighborhood.push_back(left());
	mNeighborhood.push_back(down(largeur));
	mNeighborhood.push_back(left());
	mNeighborhood.push_back(right());
	mNeighborhood.push_back(center());
	mNeighborhood.push_back(up(largeur));
	mNeighborhood.push_back(up(largeur));
	mNeighborhood.push_back(left());
	mNeighborhood.push_back(right());
	mNeighborhood.push_back(center());



	/*std::cout << (bool)mNeighborhood[0].state();
	std::cout <<" ";
	std::cout << (bool)mNeighborhood[1].state();*/

}

Cell const & SpaceSample::left() const
{
	return mStateIt == mSpace.begin() ? mSpace.back() : *std::prev(mStateIt);
}

Cell const & SpaceSample::center() const
{
	return *mStateIt;
}

Cell const & SpaceSample::up(int largeur)
{
	setStateIt(mStateIt - largeur);
	return *mStateIt;
}

Cell const & SpaceSample::down(int largeur) 
{
	

	setStateIt(mStateIt+largeur);
	return *mStateIt;
}

Cell const & SpaceSample::right() const
{
	return mStateIt == std::prev(mSpace.end()) ? mSpace.front() : *std::next(mStateIt);
}