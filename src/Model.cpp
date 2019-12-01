#include "Model.hpp"
#include "View.hpp"

Model::Model(int width, int height) {
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
<<<<<<< HEAD
	//std::cout << "index" << mIndexRule;
}

void Model::updateSpace() {
	std::vector<Cell>::const_iterator it = (*mSpace1).getSpace().begin();
	SpaceSample facade{ SpaceSample((*mSpace1).getSpace(), it, (*mSpace1).Lenght()) };
	
	std::vector<Cell>::iterator it2 = (*mSpace2).getSpace().begin();
	for (; it != (*mSpace1).getSpace().end(); it++) {
		if ((*mSpace1).Lenght() < (it - mSpace1->getSpace().begin()) < (*mSpace1).Lenght() * (*mSpace1).Height()) {
			(*it2).setState(((State)(mRules[mIndexRule].outcome(((bool)(*it).state()), facade.GetNeighbors(it)))));
		}
		++it2;
=======
}

void Model::updateSpace() {
	(*mSpace1).setBorders();
	int tHeight = mSpace1->Height();
	int tLength = mSpace1->Length();
	SpaceSample facade{mSpace1};

	for (int y{}; y < tHeight; ++y) {
		std::vector<Cell>::const_iterator it = mSpace1->getSpace()[y].begin();
		std::vector<Cell>::iterator it2 = mSpace2->getSpace()[y].begin();
		for (int x{}; x < tLength; ++x) {
			it2->setState(((State)(mRules[mIndexRule].outcome(((bool)(*it).state()), facade.GetNeighbors(y, x)))));
			++it;
			++it2;
		}
>>>>>>> ferat
	}

	Space* temp{ mSpace1 };
	mSpace1 = mSpace2;
	mSpace2 = temp;
<<<<<<< HEAD

	(*mSpace1).setBorders();
}

=======
}

unsigned int Model::indexRule() { return mIndexRule; };
>>>>>>> ferat
uint8_t Model::liveCellColor() { return mLiveCellColor;}
uint8_t Model::deadCellColor() { return mDeadCellColor;}
void Model::mSetDeadColor() {mDeadCellColor = mDeadCellColor < View::mNbColors  ?  mDeadCellColor + 1 : 0;}
void Model::mSetLiveColor() {mLiveCellColor = mLiveCellColor < View::mNbColors  ?  mLiveCellColor + 1 : 0;}
void Model::giveRLE(string fileName) { mSpace1->GenFromRLE(fileName); }
