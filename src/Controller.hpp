#ifndef CONTROLER_H
#define	CONTROLER_H

#include <array>
#include <filesystem>
#include "Model.hpp"
#include "View.hpp"
#include "KeyBinding.hpp"
#include "RLE_reader.hpp"

class Controller {

public:
	//Constructeur et Destructeur
	Controller() = delete;
	Controller(Model &model, View &view);
	~Controller() = default;

	// TODO change place
	/*
	//changer vitesse de l'animation
	void changeTime();
	*/

private:
	bool mQuit = false;
	Model &mModel;
	View &mView;
	size_t mRLEindex{ 0 };
	std::vector<string> mValidRLEfiles;

	enum class Keys : char {
		Action_Quit					= 27,	// escape character
		Action_Space				= 32, 	// space character
		Speed_x1 					= '1',
		Speed_x2					= '2',
		Speed_x3					= '3',
		Speed_x4					= '4',
		Speed_x5					= '5',
		Speed_x6					= '6',
		Speed_x7					= '7',
		Speed_x8					= '8',
		Speed_x9					= '9',
		Action_Rule					= 'r',
		Action_Border				= 'b',
		Action_ActiveCellColor 		= 'p',
		Action_DeadCellColor 		= 'o',
		GenMode_Random1 			= 'a',
		GenMode_Random5 			= 's',
		GenMode_Random10 			= 'd',
		GenMode_Random15 			= 'f',
		GenMode_Random25 			= 'g',
		GenMode_Random50 			= 'h',
		GenMode_FilePrev 			= 'z',
		GenMode_FileSame 			= 'x',
		GenMode_FileNext 			= 'c',
		_count_
	};
	KeyBinding mModelAction;

	enum class SpeedMode {
		Speed0	= 0,
		Speed1 	= 1,
		Speed2 	= 2,
		Speed3 	= 3,
		Speed4 	= 4,
		Speed5 	= 5,
		Speed6 	= 6,
		Speed7 	= 7,
		Speed8 	= 8,
		Speed9 	= 9,
		_count_
	};
	SpeedMode mSpeedMode{SpeedMode::Speed1};
	KeyBinding mSpeedAction;

	enum class GenerationMode {
		Random1 	= 0,
		Random5 	= 1,
		Random10 	= 2,
		Random15 	= 3,
		Random25 	= 4,
		Random50 	= 5,
		_count_
	};
	GenerationMode mGenerationMode{GenerationMode::Random50};
	KeyBinding mGenerationAction;

	// TODO change place
	/*
	string mPath;
	vector<string> mFile;
	std::array<int,5> mSpeed{};
	int mIndexFile{};
	int mIndexSpeed{};
	*/

public:
	void start();
	void quit();
	void mSetSpeedMode(SpeedMode speed); 
	std::vector<std::string> getRLEfiles(std::string folder);

	string currRLE();
	string getNextRLE(); 
	string getLastRLE(); 

};

#endif //CONTROLER_H
