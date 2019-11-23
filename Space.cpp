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
	if (!mBordersAlive) {

		int t{ 0 };
		for (int i{ 0 }; i < mLenght; ++i)
		{
			for (int j{ 0 }; j < mLenght; ++j)
			{
				if (t < mLenght || t % mLenght == 0 || (t + 1) % mLenght == 0 || t > mSpace.size() - mLenght)
					mSpace[t].setState(State::INACTIVE);

				t++;

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

