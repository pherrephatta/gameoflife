#include "Controller.hpp"
#include <limits>

Controller::Controller(Model &model, View &view) 
	: mModel{model}, mView{view}, mModelAction(),
	mGenerationAction(0, (int)GenerationMode::_count_), 
	mSpeedAction(0, (int)SpeedMode::_count_)
{
#define args_t Model& model, Controller& controller
	mModelAction.setAction((int)Keys::Action_Quit, [](args_t)->void{ controller.quit(); });
}

void Controller::start() {
	do {
		while (SDL_PollEvent(&mView.window().event())) {
			mModelAction.doActionFromKey(mView.window().event().key.keysym.sym, mModel, *this);
		}

		mModel.updateSpace();
		mView.mRenderModel(mModel);
	} while (!mQuit);
}

void Controller::quit() {
	mQuit = true;
}