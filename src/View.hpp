#ifndef VIEW_H
#define VIEW_H

#include <cstdint>
#include "Window.hpp"

class View {

public:
	View() = delete;
	View(uint16_t width, uint16_t height);
	~View() = default;

	void mClear(); 			// Clear the screen
	void mRenderChecker(); 	// Draw pattern, for testing purposes

private:
	Window window;
};

#endif // VIEW_H
