#ifndef WINDOW_H
#define WINDOW_H

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

#include <cstdint>

class Window {
public:
	// Window(uint16_t screen_width, uint16_t screen_height, uint16_t pixel_width, uint16_t pixel_height);
	Window(uint16_t screen_width, uint16_t screen_height);
	Window() = delete;
	~Window();

	SDL_Window*& wdHandle(); 
	SDL_Renderer*& wdRenderer();
	SDL_Texture*& wdTexture();
	SDL_Event& event(); 
	uint16_t logWidth() const;
	uint16_t logHeight() const;

private:
	uint16_t mWdWidth;									// Window width (pixels)
	uint16_t mWdHeight;									// Window height (pixels
	uint16_t mPxWidth = 3;								// Pixel logical width	
	uint16_t mPxHeight = 3;								// Pixel logical height
	uint16_t mLogWidth;									// Logical Width (wdWidth / pxWidth)
	uint16_t mLogHeight;								// Logical Height (wdHeight / pxHeight)

	SDL_Window *mWdHandle = nullptr;
	SDL_Renderer *mWdRenderer = nullptr;
	SDL_Texture *mWdTexture = nullptr;
	SDL_Event mEvent;
};

#endif // WINDOW_H