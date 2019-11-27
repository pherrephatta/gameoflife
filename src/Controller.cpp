#include "Controller.hpp"
#include <limits>
#include <functional>

Controller::Controller(Model &model, View &view) 
	: mModel{model}, mView{view}, mModelAction(),
	mGenerationAction(0, (int)GenerationMode::_count_), 
	mSpeedAction(0, (int)SpeedMode::_count_)
{
	mModelAction.setAction((int)Keys::Action_Rule, [](Model& model, Controller& controller)->void { model.nextRule(); });
	mModelAction.setAction((int)Keys::Action_Quit, [](Model& model, Controller& controller)->void { controller.quit(); });
	mModelAction.setAction((int)Keys::Action_Border, [](Model& model, Controller& controller)->void { model.space1().BordersAlive(); });
	mModelAction.setAction((int)Keys::GenMode_Random1, [](Model& model, Controller& controller)->void { model.space1().randomize(0.01); });
	mModelAction.setAction((int)Keys::GenMode_Random5, [](Model& model, Controller& controller)->void { model.space1().randomize(0.05); });
	mModelAction.setAction((int)Keys::GenMode_Random10, [](Model& model, Controller& controller)->void { model.space1().randomize(0.10); });
	mModelAction.setAction((int)Keys::GenMode_Random15, [](Model& model, Controller& controller)->void { model.space1().randomize(0.15); });
	mModelAction.setAction((int)Keys::GenMode_Random25, [](Model& model, Controller& controller)->void { model.space1().randomize(0.25); });
	mModelAction.setAction((int)Keys::GenMode_Random50, [](Model& model, Controller& controller)->void { model.space1().randomize(0.50); });
}
void Controller::start() {
	do {
		while (SDL_PollEvent(&mView.window().event())) {
			if (mView.window().event().type == SDL_KEYDOWN) {
				mModelAction.doActionFromKey(mView.window().event().key.keysym.sym, mModel, *this);
			}
		}
		mModel.updateSpace();
		mView.mRenderModel(mModel);
	} while (!mQuit);
}

void Controller::quit() {
	mQuit = true;
}
