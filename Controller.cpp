#include "Controller.hpp"
#include <limits>

Controller::Controller(Model &model, View &view) 
	: mModel{model}, mView{view} 
{
}

void Controller::handleEvents(View& view) {

	switch (view.window().event().type) {
		case SDL_WINDOWEVENT: {
			break;
		}

		case SDL_QUIT: {
			mQuit = true;
			break;
		}

		case SDL_KEYDOWN: {
			switch(view.window().event().key.keysym.sym) {
				case SDLK_ESCAPE:
					mQuit = true;
					break;

				default: break;
			}
			break;
		}

		default: break;
	}
}

void Controller::start() {
	do {
		while (SDL_PollEvent(&mView.window().event()))
			handleEvents(mView);
		mModel.updateSpace();
		mView.mRenderModel(mModel);
	} while (!mQuit);
}
