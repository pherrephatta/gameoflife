#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <cstdint>

class Window {
public:
	// Window(uint16_t screen_width, uint16_t screen_height, uint16_t pixel_width, uint16_t pixel_height);
	Window(uint16_t screen_width, uint16_t screen_height);
	Window() = delete;
	~Window();

	SDL_Window* wdHandle(); 
	SDL_Renderer* wdRenderer();
	uint16_t logWidth();
	uint16_t logHeight();

private:
	uint16_t mWdWidth;									// Window width (pixels)
	uint16_t mWdHeight;									// Window height (pixels
	uint16_t mPxWidth = 5;								// Pixel logical width	
	uint16_t mPxHeight = 5;								// Pixel logical height
	uint16_t mLogWidth;									// Logical Width (wdWidth / pxWidth)
	uint16_t mLogHeight;								// Logical Height (wdHeight / pxHeight)

	SDL_Window *mWdHandle = nullptr;
	SDL_Renderer *mWdRenderer = nullptr;
};

#endif // WINDOW_H
