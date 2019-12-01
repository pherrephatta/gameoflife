#ifndef SPACE_H
#define SPACE_H

#include <vector>
#include <string>
#include "Cell.hpp"

class Space
{
private:
	std::vector<std::vector<Cell>> mSpace;
	int mLength;
	int mHeight;
	bool mBordersAlive = true;

public:
	Space() = default;
	Space(int lenght, int height);
	~Space() = default;

	//////////////////////////////////////////////////////////////////////////
	//! \brief Accesseur de l'état
	//////////////////////////////////////////////////////////////////////////
	std::vector<std::vector<Cell>> & getSpace();

	void setBorders();
	void BordersAlive();
	void wipeSpace();
	void randomize(double probability = 0.5);
	int Length();
	int Height();
	void GenFromRLE(std::string s);

	//Necessaire ou non?
	//Effectue la conversion entre un état et un caractère.
	//char toChar() const;
	//static void setRepresentation(char inactive, char active);
};

#endif // SPACE_H
