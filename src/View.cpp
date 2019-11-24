#include "View.hpp"

View::View(uint16_t width, uint16_t height) 
	: window(width, height) 
{
	printf("%d, %d\n", window.logWidth(), window.logHeight());
}

// Clears the window's content and sets to black
void View::mClear() {
	SDL_SetRenderDrawColor(window.wdRenderer(), 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(window.wdRenderer());
}

void View::mRenderChecker() {
	mClear();
	for (int y{0}; y < window.logHeight(); y++) {
		for (int x{0}; x < window.logWidth(); x++) {
			int color = (x + y) % 2 == 0 ? 255 : 0;
			SDL_SetRenderDrawColor(window.wdRenderer(), color, color, color, SDL_ALPHA_OPAQUE);
			SDL_RenderDrawPoint(window.wdRenderer(), x, y);
		}
	}
	SDL_RenderPresent(window.wdRenderer());
}
