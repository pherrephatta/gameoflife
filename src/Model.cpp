#include "Model.hpp"


Model::Model(int width, int height) {
	mSpace1 = new Space(width, height);
	mSpace2 = new Space(*mSpace1);
}

Space& Model::space1() { return *mSpace1; }
Space& Model::space2() { return *mSpace2; }

void Model::updateSpace() {
	std::vector<Cell>::const_iterator it = (*mSpace1).getSpace().begin();
	SpaceSample facade{ SpaceSample((*mSpace1).getSpace(), it, (*mSpace1).Lenght()) };

	std::vector<Cell>::iterator it2 = (*mSpace2).getSpace().begin();


	for (; it != (*mSpace1).getSpace().end(); it++) {
		(*it2).setState(((State)(regle1.outcome(((bool)(*it).state()), facade.GetNeighbors(it)))));
		++it2;
	}

	Space* temp{ mSpace1 };
	mSpace1 = mSpace2;
	mSpace2 = temp;

}
