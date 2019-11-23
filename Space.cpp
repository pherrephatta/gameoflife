#include "Space.h"
#include "Cell.h"



#include <algorithm>
#include <sstream>
#include <iostream>



Space::Space(int lenght, int height)
	: mSpace(lenght*height), mLenght{ lenght }, mHeight{ height }
{
	randomize();
	setBorders();
}





std::vector<Cell> const & Space::getSpace() const
{
	return mSpace;
}

void Space::setSpace() {

	//RLE 

}

void Space::setBorders()
{	
	if (!mBordersAlive){
		for (std::vector<Cell>::iterator it =mSpace.begin(); it != mSpace.end(); ++it) {
			int index = (it- mSpace.begin());
			std::cout << index << " ";
			//if (index < mLenght || index % mLenght == 0 || index + 1 % mLenght == 0 || (it - mSpace.begin() < (mLenght - 1))) 
			if (mSpace.begin() - it < mLenght)				{
				(*(it)).setState(State::INACTIVE);
			
			}
		}
	}

}





void Space::BordersAlive(bool b)
{
	mBordersAlive = b;
}

void Space::randomize(double probability) {

	std::for_each(mSpace.begin(), mSpace.end(), [probability](Cell & cell)->void { cell.randomize(probability); });

}

