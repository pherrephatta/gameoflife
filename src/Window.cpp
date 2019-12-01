#include "Window.hpp"
#include <cstdio>

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

		mLogWidth = mWdWidth / mPxWidth; 		// Logical screen width
		mLogHeight = mWdHeight / mPxHeight; 	// Logical screen height
		SDL_RenderSetLogicalSize(mWdRenderer, mLogWidth, mLogHeight);

		mWdTexture = SDL_CreateTexture
		(
			mWdRenderer,
			SDL_PIXELFORMAT_RGBA32,
			SDL_TEXTUREACCESS_TARGET,
			mLogWidth,
			mLogHeight
		);
	}
}

Window::~Window() {
	SDL_DestroyRenderer(mWdRenderer);
	SDL_Quit();
}

SDL_Window*& Window::wdHandle() {return mWdHandle;} 
SDL_Renderer*& Window::wdRenderer() {return mWdRenderer;}
SDL_Texture*& Window::wdTexture() { return mWdTexture; }
SDL_Event& Window::event() {return mEvent;}
uint16_t Window::logWidth() const {return mLogWidth;}
uint16_t Window::logHeight() const {return mLogHeight;}
