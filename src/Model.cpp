#include "Model.hpp"
#include "View.hpp"

Model::Model(size_t width, size_t height) {
	mSpace1 = new Space(width, height);
	mSpace2 = new Space(*mSpace1);
	mDeadCellColor = View::mNbColors / 2;
}

Model::~Model() {
	delete mSpace1;
	delete mSpace2;
}

Space& Model::space1() { return *mSpace1; }
Space& Model::space2() { return *mSpace2; }

void Model::nextRule(){
	(mIndexRule == (mRules.size() - 1)) ? mIndexRule = 0 : ++mIndexRule;
}

void Model::updateSpace() {
	(*mSpace1).setBorders();
	size_t tHeight = mSpace1->Height();
	size_t tLength = mSpace1->Length();
	SpaceSample facade{mSpace1};

	for (size_t y{}; y < tHeight; ++y) {
		std::vector<Cell>::const_iterator it = mSpace1->getSpace()[y].begin();
		std::vector<Cell>::iterator it2 = mSpace2->getSpace()[y].begin();
		for (size_t x{}; x < tLength; ++x) {
			it2->setState(((State)(mRules[mIndexRule].outcome(((bool)(*it).state()), facade.GetNeighbors(y, x)))));
			++it;
			++it2;
		}
	}

	Space* temp{ mSpace1 };
	mSpace1 = mSpace2;
	mSpace2 = temp;
}

unsigned int Model::indexRule() { return mIndexRule; };
uint8_t Model::liveCellColor() { return mLiveCellColor;}
uint8_t Model::deadCellColor() { return mDeadCellColor;}
void Model::mSetDeadColor() {mDeadCellColor = mDeadCellColor < View::mNbColors  ?  mDeadCellColor + 1 : 0;}
void Model::mSetLiveColor() {mLiveCellColor = mLiveCellColor < View::mNbColors  ?  mLiveCellColor + 1 : 0;}
void Model::giveRLE(string fileName) { mSpace1->GenFromRLE(fileName); }
