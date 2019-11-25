#ifndef KEYBINDING_H 
#define KEYBINDING_H

#include <vector>

class Model;
class Controller;

class KeyBinding {
public:
	using key_t = int;
	using action_t = void(*)(Model& model, Controller& controller);

	KeyBinding();
	KeyBinding(key_t fromKey, key_t toKey);
	~KeyBinding() = default;

	void setAction(key_t key, action_t action);
	void setDefaultAction(action_t action);
	void doActionFromKey(key_t key, Model& model, Controller& controller) const;
	void doDefaultAction(Model& model, Controller& controller) const;

private:
	key_t mOffsetKey;
	std::vector<action_t> mBinding;
	action_t mDefaultAction = nullptr;
};

#endif // KEYBINDING_H