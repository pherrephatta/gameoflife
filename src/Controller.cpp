#include "Controller.hpp"
#include <limits>

Controller::Controller(Model &model, View &view) 
	: mModel{model}, mView{view} 
{
}

void Controller::start() {
	do {
		mView.mRenderChecker();
	} while (!mQuit);
}
