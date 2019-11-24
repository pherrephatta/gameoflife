#include "Window.hpp"

Window::Window(uint16_t screen_width, uint16_t screen_height) {
	// SDL Initialization
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_EVENTS) != 0) {
		printf("SDL_INIT_FAILURE\n");
		exit(0);
	} else {
		mWdWidth = screen_width; 		// True screen width
		mWdHeight = screen_height; 		// True screen height

		// Window Creation
		mWdHandle = SDL_CreateWindow
		(
			"Game of Life",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			mWdWidth,
			mWdHeight,
			SDL_WINDOW_SHOWN
		);

		// Renderer Creation
		mWdRenderer = SDL_CreateRenderer
		(
			mWdHandle,
			-1,
			SDL_RENDERER_ACCELERATED
		);

		mLogWidth = mWdWidth / mPxWidth; 		// Logical screen width (5x5 pixels)
		mLogHeight = mWdHeight / mPxHeight; 	// Logical screen height (5x5 pixels)
		SDL_RenderSetLogicalSize(mWdRenderer, mLogWidth, mLogHeight);
	}
}

Window::~Window() {
	SDL_Quit();
}

SDL_Window* Window::wdHandle() {return mWdHandle;} 
SDL_Renderer* Window::wdRenderer() {return mWdRenderer;}
uint16_t Window::logWidth() {return mLogWidth;}
uint16_t Window::logHeight() {return mLogHeight;}
