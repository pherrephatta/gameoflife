#ifndef MODEL_H 
#define	MODEL_H

#include "Space.hpp"
#include "Rule.hpp"
#include "SpaceSample.hpp"
#include "Cell.hpp"
#include <iostream>

class Model {

public:
	Model() = delete;
	Model(int width, int height);
	~Model();

	//mettre a jour l'espace
	void updateSpace();
	Space& space1();
	Space& space2();
	unsigned int indexRule();
	void nextRule();
	void giveRLE(string fileName); //give a RLE file to currSpace. i.e. reset it with that new pattern
	uint8_t deadCellColor();
	uint8_t liveCellColor();
	void mSetDeadColor();
	void mSetLiveColor();

private:
	//vector<Rule> mRule;
	Space* mSpace1 = nullptr;
	Space* mSpace2 = nullptr;
	Rule regle1{ Rule("123", "456") };
	std::vector<Rule> mRules{ Rule("3", "23"), Rule("36", "23") , Rule("3678", "34678"), Rule("1", "7") };

	uint8_t mDeadCellColor{};
	uint8_t mLiveCellColor{};
	unsigned int mIndexRule{};
};

#endif	//MODEL_H
