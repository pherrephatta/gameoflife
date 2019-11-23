#include "SpaceSample.h"
#include <iostream>

SpaceSample::SpaceSample(std::vector <Cell> const & space, std::vector<Cell>::const_iterator stateIt, int largeur)
	: mSpace{ space }, mStateIt{ stateIt }, mLargeur{ largeur }
{
	mStateIt_haut = mStateIt;
	mStateIt_bas = mStateIt;
	
	
}

std::vector<State> SpaceSample::Neighborhood()
{
	return std::vector<State>();
}

int SpaceSample::calculateNeighborhood()
{
	//TODO: Clear Vecteur ou Effacer ceux qu'on a plus besoin 
	int nb_of_neighbors{};
	for (int i{}; i < mNeighborhood.size(); ++i)
	{
		nb_of_neighbors += (int)mNeighborhood[i].state();
	}
	return nb_of_neighbors;
}

void SpaceSample::GetNeighbors(std::vector<Cell>::const_iterator it)
{
	
	setIterateurs(it);
	up();
	middle(); 
	down(); 
	std::cout << "nb de voisins : " << calculateNeighborhood() << std::endl;
	mNeighborhood.clear();
}

Cell const & SpaceSample::center(std::vector<Cell>::const_iterator it) const
{
	return *it;
}

void SpaceSample::up()
{

	if ((int)(mStateIt - mSpace.begin()) < mLargeur)
	{
		mStateIt_haut = (mSpace.end() - mLargeur + (mStateIt - mSpace.begin()));
	}
	else mStateIt_haut =(mStateIt - mLargeur);
	
	mNeighborhood.push_back(left(mStateIt_haut));
	mNeighborhood.push_back(center(mStateIt_haut));
	mNeighborhood.push_back(right(mStateIt_haut));
}

void SpaceSample::middle()
{

	mNeighborhood.push_back(left(mStateIt));
	mNeighborhood.push_back(right(mStateIt));
}

void SpaceSample::down() 
{
	if ((int)(mStateIt - mSpace.begin()) >= (mSpace.size()-mLargeur))
		mStateIt_bas=(mSpace.begin() + ((mStateIt - mSpace.begin())% mLargeur));
	else mStateIt_bas=(mStateIt + mLargeur);	

	mNeighborhood.push_back(left(mStateIt_bas));
	mNeighborhood.push_back(center(mStateIt_bas));
	mNeighborhood.push_back(right(mStateIt_bas));
}

void SpaceSample::setIterateurs(std::vector<Cell>::const_iterator it)
{
	mStateIt = it;
	mStateIt_bas = it;
	mStateIt_haut = it;
}


Cell const & SpaceSample::right(std::vector<Cell>::const_iterator it) const
{

	if (it == mSpace.end() - 1)
		return  *(it - mLargeur + 1);
	else if (it - mSpace.begin() == (mLargeur - 1))
		return  *(it +1 - mLargeur);
	else if ((((it - mSpace.begin()) + 1) % (mLargeur)) == 0) {	
		return *(it - mLargeur + 1);
	}
	else
		return *std::next(it);
}

Cell const & SpaceSample::left(std::vector<Cell>::const_iterator it) const 
{
	if (it == mSpace.begin())
	{
		return  *(it + mLargeur - 1);
	}else if ((it-mSpace.begin()) % mLargeur == 0)
		return  *(it+(mLargeur-1));
	else
		return *std::prev(it);
}
