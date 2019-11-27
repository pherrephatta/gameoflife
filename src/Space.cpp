#include "Space.hpp"
#include "Cell.hpp"
#include "RLE_reader.hpp"



#include <algorithm>
#include <sstream>
#include <iostream>



Space::Space(int length, int height)
	: mSpace(length*height), mLenght{ length }, mHeight{ height }
{
	setSpaceMid();
}

std::vector<Cell>  & Space::getSpace()
{
	return mSpace;
}

void Space::setSpaceMid() { //sets the space with the read RLE pattern in the middle

	RLE_reader r("gosperglidergungliderdestruction.rle");
	r.analyzeFile();
	vector<bool> RLE_universe = r.ExportUniverse();

	size_t cpt_pattern{ 0 }; //counter for width of rle pattern, when we get to its max value, we put the space cursor at the correct following XY.
	size_t patternWidth{ r.rleWidth() };
	size_t SpaceCursor{ ((size_t)(mLenght*mHeight) / 2) };
	SpaceCursor -= (r.rleWidth() / 2);
	SpaceCursor -= (r.rleHeight()*mLenght)/2;
 //position in our model/space	//eventually add method to return cursor at XY where the printed pattern will appear 

	for (bool b : RLE_universe) {
		mSpace[SpaceCursor].setState(b ? State::ACTIVE : State::INACTIVE);
		++cpt_pattern;
		++SpaceCursor;
		if (cpt_pattern >= patternWidth) {
			cpt_pattern=0;
			SpaceCursor += (mLenght - r.rleWidth());
		}
		
	}
}

void Space::setBorders()
{
	if (!mBordersAlive) {

		int t{ 0 };
		for (int i{ 0 }; i < mLenght; ++i)
		{
			for (int j{ 0 }; j < mLenght; ++j)
			{
				if (t < mLenght || t % mLenght == 0 || (t + 1) % mLenght == 0 || (t > int(mSpace.size() - mLenght)))
					mSpace[t].setState(State::INACTIVE);

				t++;

			}
		}

	}
}




void Space::BordersAlive()
{
	mBordersAlive = !mBordersAlive;
	//std::cout << "borders changed";
}

void Space::randomize(double probability) {

	std::for_each(mSpace.begin(), mSpace.end(), [probability](Cell & cell)->void { cell.randomize(probability); });
	//std::cout << "randomize with a probability of " << probability;

}

