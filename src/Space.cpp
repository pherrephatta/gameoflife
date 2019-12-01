#include "Space.hpp"
#include "Cell.hpp"
#include "RLE_reader.hpp"

#include <algorithm>
#include <sstream>
#include <iostream>

int Space::Length() { return mLength; }
int Space::Height() { return mHeight; }
std::vector<std::vector<Cell>> &Space::getSpace() {	return mSpace; }

Space::Space(int length, int height)
	: mSpace(length*height), mLength{ length }, mHeight{ height }
{
}

void Space::wipeSpace() {
	for (int y{}; y < mHeight; ++y) {
		for (int x{}; x < mLength; ++x) {
			mSpace[y][x].setState(State::INACTIVE);
		}
	}
}

void Space::GenFromRLE(string s) {
	RLE_reader r(s); //s must be valid RLE file, recommended to call this function only by using strings from the mValidRLEfiles vector

	bool valid = r.analyzeFile();
	size_t patternWidth{ r.rleWidth() };
	size_t patternHeight{ r.rleHeight()};
	if (valid && patternWidth < mLength && patternHeight < mHeight) {
		wipeSpace(); //if RLE extraction is successful, we wipe the curr space and print our RLE pattern on it. If not we carry on as usual
		vector<bool> RLE_universe = r.ExportUniverse();

		size_t cpt_pattern{ 0 }; //counter for width of rle pattern, when we get to its max value, we put the space cursor at the correct following XY.

		// Find upper left corner of the vector space (to center pattern)
		size_t midX = mLength - (patternWidth / 2);
		size_t midY = mHeight - (patternHeight / 2);

		size_t X = midX;
		size_t Y = midY;
		for (bool b : RLE_universe) {

			mSpace[Y][X].setState(b ? State::ACTIVE : State::INACTIVE);
			++cpt_pattern;
			++X;
			if (cpt_pattern >= patternWidth) {
				cpt_pattern = 0;
				++Y;
				X = midX;
			}
		}
	}
}

void Space::setBorders()
{
	if (!mBordersAlive) {
		for (int y{}; y < mHeight; ++y) {
			if (y == 0 || y == mHeight - 1) {
				for (int x{}; x < mLength; ++x) {
					mSpace[y][x].setState(State::INACTIVE);
				}
			} else {
				mSpace[y][0].setState(State::INACTIVE);
				mSpace[y][mLength - 1].setState(State::INACTIVE);
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

