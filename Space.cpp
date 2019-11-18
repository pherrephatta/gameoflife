#include "Space.h"
#include "Cell.h"

#include <algorithm>

Space::Space(int lenght, int height)
	: mSpace(lenght*height), mLenght{ lenght }, mHeight{ height }
{
}


void Space::setSpace() {
	//RLE 
}


void Space::randomize(double probability) {
	std::for_each(mSpace.begin(), mSpace.end(), [probability](Cell & cell)->void { cell.randomize(probability); });
}


