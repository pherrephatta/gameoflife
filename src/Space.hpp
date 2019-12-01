#ifndef SPACE_H
#define SPACE_H

#include <vector>
#include <string>
#include "Cell.hpp"

class Space
{
private:
	std::vector<std::vector<Cell>> mSpace;
	size_t mLength;
	size_t mHeight;
	bool mBordersAlive = true;

public:
	Space() = default;
	Space(size_t lenght, size_t height);
	~Space() = default;

	//////////////////////////////////////////////////////////////////////////
	//! \brief Accesseur de l'état
	//////////////////////////////////////////////////////////////////////////
	std::vector<std::vector<Cell>> & getSpace();

	void setBorders();
	void BordersAlive();
	void wipeSpace();
	void randomize(double probability = 0.5);
	size_t Length();
	size_t Height();
	void GenFromRLE(std::string s);

	//Necessaire ou non?
	//Effectue la conversion entre un état et un caractère.
	//char toChar() const;
	//static void setRepresentation(char inactive, char active);
};

#endif // SPACE_H
