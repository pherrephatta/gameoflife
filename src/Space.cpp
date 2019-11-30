#include "Space.hpp"
#include "Cell.hpp"
#include "RLE_reader.hpp"

#include <algorithm>
#include <sstream>
#include <iostream>



Space::Space(int length, int height)
	: mSpace(length*height), mLenght{ length }, mHeight{ height }
{
	setSpace();
}

std::vector<Cell>  & Space::getSpace()
{
	return mSpace;
}

void Space::setSpace() {

}

void Space::wipeSpace() {
	for (int i{ 0 }; i < mLenght*mHeight; ++i) {
		mSpace[i].setState(State::INACTIVE);
	}
}

void Space::GenFromRLE(string s) {
	RLE_reader r(s); //s must be valid RLE file, recommended to call this function only by using strings from the mValidRLEfiles vector

	bool valid = r.analyzeFile();
	size_t patternWidth{ r.rleWidth() };
	size_t patternHeight{ r.rleHeight()};
	if (valid && patternWidth < mLenght && patternHeight < mHeight) {
		wipeSpace(); //if RLE extraction is successful, we wipe the curr space and print our RLE pattern on it. If not we carry on as usual
		vector<bool> RLE_universe = r.ExportUniverse();

		size_t cpt_pattern{ 0 }; //counter for width of rle pattern, when we get to its max value, we put the space cursor at the correct following XY.
		size_t mid = mSpace.size() / 2; //middle of contiguous space
		size_t SpaceCursor{ mid - (patternWidth / 2) - (patternHeight*mLenght / 2) }; //to start printing a pattern in the middle, we find its upper left corner in relation to the center of the space.
	
		for (bool b : RLE_universe) {
			mSpace[SpaceCursor].setState(b ? State::ACTIVE : State::INACTIVE);
			++cpt_pattern;
			++SpaceCursor;
			if (cpt_pattern >= patternWidth) {
				cpt_pattern = 0;
				SpaceCursor += (mLenght - patternWidth);
			}
		}
	
	}

}

void Space::setBorders()
{
	if (!mBordersAlive) {
		int t{ 0 };
		for (int i{ 0 }; i < mHeight; ++i)
		{
			for (int j{ 0 }; j < mLenght; ++j)
			{
				if (t < mLenght || t % mLenght == 0 || (t + 1) % mLenght == 0 || (t > int(mSpace.size() - mLenght)))
					mSpace[t].setState(State::INACTIVE);
				t++;

			}
		}
	}
	else {
		for (int y{}; y < mHeight; ++y) {
			if (y == 0) {
				for (int x{}; x < mLenght; ++x) {
					mSpace[x].setState(mSpace[mLenght * y + x].state());
				}
			}
			else if (y == mHeight - 1) {
				for (int x{}; x < mLenght; ++x) {
					mSpace[x].setState(mSpace[x].state());
				}
			}
			else {
				Cell temp(mSpace[y * mLenght]);
				mSpace[y * mLenght].setState(mSpace[y * (mLenght + 1) - 1].state());
				mSpace[y * (mLenght + 1) - 1].setState(temp.state());
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

