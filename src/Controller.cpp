#include "Controller.hpp"
#include <limits>

Controller::Controller(Model &model, View &view) 
	: mModel{model}, mView{view}, mModelAction(),
	mGenerationAction(0, (int)GenerationMode::_count_), 
	mSpeedAction(0, (int)SpeedMode::_count_)
{
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	mValidRLEfiles = getRLEfiles("./rle/");
#else
	mValidRLEfiles = getRLEfiles("../rle/");
#endif
	mModelAction.setAction((int)Keys::Action_Quit, [](Model& model, Controller& controller)->void { controller.quit(); });
	mModelAction.setAction((int)Keys::Action_Border, [](Model& model, Controller& controller)->void { model.space1().BordersAlive(); });
	mModelAction.setAction((int)Keys::GenMode_Random1, [](Model& model, Controller& controller)->void { model.space1().randomize(0.01); });
	mModelAction.setAction((int)Keys::GenMode_Random5, [](Model& model, Controller& controller)->void { model.space1().randomize(0.05); });
	mModelAction.setAction((int)Keys::GenMode_Random10, [](Model& model, Controller& controller)->void { model.space1().randomize(0.10); });
	mModelAction.setAction((int)Keys::GenMode_Random15, [](Model& model, Controller& controller)->void { model.space1().randomize(0.15); });
	mModelAction.setAction((int)Keys::GenMode_Random25, [](Model& model, Controller& controller)->void { model.space1().randomize(0.25); });
	mModelAction.setAction((int)Keys::GenMode_Random50, [](Model& model, Controller& controller)->void { model.space1().randomize(0.50); });
	mModelAction.setAction((int)Keys::Speed_x1, [](Model& model, Controller& controller)->void { controller.mSetSpeedMode(SpeedMode::Speed1); });
	mModelAction.setAction((int)Keys::Speed_x2, [](Model& model, Controller& controller)->void { controller.mSetSpeedMode(SpeedMode::Speed2); });
	mModelAction.setAction((int)Keys::Speed_x3, [](Model& model, Controller& controller)->void { controller.mSetSpeedMode(SpeedMode::Speed3); });
	mModelAction.setAction((int)Keys::Speed_x4, [](Model& model, Controller& controller)->void { controller.mSetSpeedMode(SpeedMode::Speed4); });
	mModelAction.setAction((int)Keys::Speed_x5, [](Model& model, Controller& controller)->void { controller.mSetSpeedMode(SpeedMode::Speed5); });
	mModelAction.setAction((int)Keys::Speed_x6, [](Model& model, Controller& controller)->void { controller.mSetSpeedMode(SpeedMode::Speed6); });
	mModelAction.setAction((int)Keys::Speed_x7, [](Model& model, Controller& controller)->void { controller.mSetSpeedMode(SpeedMode::Speed7); });
	mModelAction.setAction((int)Keys::Speed_x8, [](Model& model, Controller& controller)->void { controller.mSetSpeedMode(SpeedMode::Speed8); });
	mModelAction.setAction((int)Keys::Speed_x9, [](Model& model, Controller& controller)->void { controller.mSetSpeedMode(SpeedMode::Speed9); });
	mModelAction.setAction((int)Keys::Action_Rule, [](Model& model, Controller& controller)->void { model.nextRule(); });
	mModelAction.setAction((int)Keys::Action_ActiveCellColor, [](Model& model, Controller& controller)->void { model.mSetLiveColor(); });
	mModelAction.setAction((int)Keys::Action_DeadCellColor, [](Model& model, Controller& controller)->void { model.mSetDeadColor(); });
	mModelAction.setAction((int)Keys::GenMode_FileNext, [](Model& model, Controller& controller)->void {model.giveRLE(controller.getNextRLE());});
	mModelAction.setAction((int)Keys::GenMode_FilePrev, [](Model& model, Controller& controller)->void {model.giveRLE(controller.getLastRLE()); });
	mModelAction.setAction((int)Keys::GenMode_FileSame, [](Model& model, Controller& controller)->void {model.giveRLE(controller.currRLE()); });
}

string Controller::currRLE() { return mValidRLEfiles[mRLEindex]; }
string Controller::getNextRLE() { return mValidRLEfiles.at(mRLEindex > mValidRLEfiles.size() ? 0 : ++mRLEindex); }
string Controller::getLastRLE() { return mValidRLEfiles.at(mRLEindex <= 0 ? mValidRLEfiles.size() - 1 : --mRLEindex); }

void Controller::start() {
	do {
		while (SDL_PollEvent(&mView.window().event())) {

			if (mView.window().event().type == SDL_KEYDOWN) {
				mModelAction.doActionFromKey(mView.window().event().key.keysym.sym, mModel, *this);
			}
		}
		mView.mRenderModel(mModel);
		for (int n = 0; n <= int(mSpeedMode) * 2; ++n) {
			mModel.updateSpace();
		}
	} while (!mQuit);
}

void Controller::quit() {
	SDL_DestroyTexture(mView.window().wdTexture());
	SDL_DstroyRenderer(mView.window().wdRenderer());
	mQuit = true;
}

void Controller::mSetSpeedMode(SpeedMode speed) {
	mSpeedMode = speed;
}

std::vector<std::string> Controller::getRLEfiles(std::string folder) {
	std::vector<std::string> files;
	for (auto& file : std::filesystem::directory_iterator(folder)) {
		if (file.is_regular_file()) {
			std::filesystem::path path = file;
			RLE_reader r(path.string());
			if (std::filesystem::file_size(path) < 10000 && r.analyzeFile()) { //if files are very big, we only analyze them when they are specifically chosen, at wich point we verify data coherence as we go along with the specified actual parameters(namely, height and lenght)
				files.push_back(path.string()); //if files are invalid, we dont keep them in the vector. 
			} 
		} 
	}
	return files;
}
