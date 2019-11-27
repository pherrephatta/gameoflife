#include "Controller.hpp"
#include <limits>

Controller::Controller(Model &model, View &view) 
	: mModel{model}, mView{view}, mModelAction(),
	mGenerationAction(0, (int)GenerationMode::_count_), 
	mSpeedAction(0, (int)SpeedMode::_count_)
{
#define args_t Model& model, Controller& controller
	mModelAction.setAction((int)Keys::Action_Quit, [](args_t)->void { controller.quit(); });
	mModelAction.setAction((int)Keys::Action_Border, [](args_t)->void { model.space1().BordersAlive(); });
	mModelAction.setAction((int)Keys::GenMode_Random1, [](args_t)->void { model.space1().randomize(0.01); });
	mModelAction.setAction((int)Keys::GenMode_Random5, [](args_t)->void { model.space1().randomize(0.05); });
	mModelAction.setAction((int)Keys::GenMode_Random10, [](args_t)->void { model.space1().randomize(0.10); });
	mModelAction.setAction((int)Keys::GenMode_Random15, [](args_t)->void { model.space1().randomize(0.15); });
	mModelAction.setAction((int)Keys::GenMode_Random25, [](args_t)->void { model.space1().randomize(0.25); });
	mModelAction.setAction((int)Keys::GenMode_Random50, [](args_t)->void { model.space1().randomize(0.50); });
	mModelAction.setAction((int)Keys::Action_Rule, [](args_t)->void { model.nextRule(); });
	

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