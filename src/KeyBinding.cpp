#include <limits>
#include "KeyBinding.hpp"

KeyBinding::KeyBinding()
	: KeyBinding(std::numeric_limits<char>::min(), std::numeric_limits<char>::max())
{
}

KeyBinding::KeyBinding(key_t fromKey, key_t toKey) 
	: mOffsetKey{fromKey}, mBinding(toKey - fromKey + 1)
{
	std::fill(mBinding.begin(), mBinding.end(), nullptr);
}

void KeyBinding::setAction(key_t key, action_t action) {
	mBinding[key - mOffsetKey] = action;
}

void KeyBinding::setDefaultAction(action_t action) {
	mDefaultAction = action;
}

void KeyBinding::doActionFromKey(key_t key, Model& model, Controller& controller) const
{
	int index{key - mOffsetKey};
	if (index >= 0 && index < (int)mBinding.size() && mBinding[index]) {
		mBinding[key - mOffsetKey](model, controller);
	} else {
		doDefaultAction(model, controller);
	}
}

void KeyBinding::doDefaultAction(Model& model, Controller& controller) const {
	if (mDefaultAction) {
		mDefaultAction(model, controller);
	}
}