#include "Cell.hpp"

Cell::Cell(State state)
{
	mState = state;
}

State Cell::state() const
{
	return mState;
}

void Cell::setState(State state)
{
	mState = state;
}

void Cell::randomize(double probability)
{
	mState = (State)RandomUtil::generateEvent(probability);
}
