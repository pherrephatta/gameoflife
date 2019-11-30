#include <cassert>
#include "RandomUtil.hpp"
#include "View.hpp"

Window& View::window() {return mWindow;}

View::View(uint16_t width, uint16_t height) 
	: mWindow(width, height) 
{
	printf("%d, %d\n", mWindow.logWidth(), mWindow.logHeight());
	mSetColors();
	printf("test\n");
}

void View::mClear() {
	SDL_SetRenderDrawColor(mWindow.wdRenderer(), 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(mWindow.wdRenderer());
}

void View::mRenderChecker() {
	mClear();
	for (size_t y{0}; y < mWindow.logHeight(); y++) {
		for (size_t x{0}; x < mWindow.logWidth(); x++) {
			int color = (x + y) % 2 == 0 ? 255 : 0;
			SDL_SetRenderDrawColor(mWindow.wdRenderer(), color, color, color, SDL_ALPHA_OPAQUE);
			SDL_RenderDrawPoint(mWindow.wdRenderer(), x, y);
		}
	}
	SDL_RenderPresent(mWindow.wdRenderer());
}

void View::mRenderModel(Model& model) { 
	assert(model.space1().Lenght() * model.space1().Height() == mWindow.logWidth() * mWindow.logHeight());
	int pos{};
	SDL_Color color{};
	mClear();
	for (size_t y{0}; y < mWindow.logHeight(); ++y) {
		for (size_t x{0}; x < mWindow.logWidth(); ++x) {
			pos = (y * model.space1().Lenght()) + x;
			color = model.space1().getSpace()[pos].state() == State::ACTIVE ? mPalette[model.liveCellColor()] : mPalette[model.deadCellColor()];
			SDL_SetRenderDrawColor(mWindow.wdRenderer(), color.r, color.g, color.b, color.a);
			SDL_RenderDrawPoint(mWindow.wdRenderer(), x, y);
		}
	}
	SDL_RenderPresent(mWindow.wdRenderer());
}

void View::mSetColors(){
	for (size_t i{0}; i < mNbColors; ++i) {
		mPalette[i].r = RandomUtil::generateChar();
		mPalette[i].g = RandomUtil::generateChar();
		mPalette[i].b = RandomUtil::generateChar();
		mPalette[i].a = 255; 
	}
}
