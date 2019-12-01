#ifndef VIEW_H
#define VIEW_H

#include <cstdint>
#include "Window.hpp"
#include "Model.hpp"

class View {

public:
	View() = delete;
	View(uint16_t width, uint16_t height);
	~View() = default;

	Window& window();							// return window

	void mClear();								// Clear the screen
	void mRenderModel(Model& model); 			// Render the model
	const static size_t mNbColors = 255;

private:
	Window mWindow;
	SDL_Color mPalette[mNbColors];
	void mSetColors();
};

#endif // VIEW_H