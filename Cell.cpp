#include "Cell.hpp"

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
