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
	void mRenderChecker();						// Draw pattern, for testing purposes
	void mRenderModel(Model& model); 		// Render the model

private:
	Window mWindow;
};

#endif // VIEW_H
