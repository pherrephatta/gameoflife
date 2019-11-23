#include "RLE_reader.h"
#include <iostream>
#include <filesystem>

RLE_reader::RLE_reader(string s) 
	:mRLEfile{s}{
	
	if (!mRLEfile.is_open()) { cout << "Cannot open RLE file" << endl; }

}

bool RLE_reader::analyzeFile() {
	smatch s;
	string line;
	bool inComments{ true };
	bool endOfFile{ false };

	while (mRLEfile.is_open()) {
		while (mRLEfile.good() && inComments) {

			getline(mRLEfile, line);
			inComments = regex_match(line, s, mRgxComments);
			if (!inComments) {
				regex_match(line, s, mRgxInitLine);
				//cout << s[0].str()<<endl;
				if (s.length() > 0) {
					mXWidth = stoi(s[1].str());
					mYHeight = stoi(s[2].str());
					if (mXWidth <1 || mYHeight <1) {
						cout << "invalid size parameters"  << endl; //will likely never be reached b/c the regex makes sure there are no '-' in the line
						return false;
					}
					regex_match(line, s, mRgxRuleFormat);//validation optionnelle de la regle
					if (s.length() > 0) {
						mRuleB = s[1].str();
						mRuleS = s[2].str();
					//we can "exit" the header with all necessary info
					}
					else{
						cout << "invalid or inexistent rule format" << endl;
					}
				}
				else {
					cout << "Empty file, invalid comment, syntaxically invalid/inexistent initilization line, or invalid x y parameters" << endl;
					cout << "Encountered error : " << line << endl;
					//verification: we 1st check if we are in a valid comment(if we are, repeat). If not, we check for the init line regex. If it fails then its either an empty file, invalid commend, or bad init line. 
					//verif presumes there are no useless newline chars.
					return false;
				}
			}
		}

		while (mRLEfile.good() && !endOfFile) { //data part
			getline(mRLEfile, line, '$');//takes following lines with $ as separator (bob$3o! = 2 lines)
			line.erase(remove(line.begin(), line.end(), '\n'), line.end());
			RLEbuffer b(line, mXWidth);
			if (mExportUniverse.size()>(mXWidth*mYHeight)) {
				cout << "Pattern overflow" << endl;
				return false;
			}
			else if (b.analyzeDataString()) {
			
				vector<bool> freshUniverse = b.ExtractedUniverse();
				mExportUniverse.insert(mExportUniverse.end(), freshUniverse.begin(), freshUniverse.end());
				endOfFile = b.done();
				//cout << line << "			freshU size:" << freshUniverse.size() << "			";
				//cout << "Universe size after line : " << mExportUniverse.size() << endl << endl;
			}
			else {
				cout << "incoherence in data (x overflow most likely)";
				return false;
			}

		}

		mRLEfile.close();
	}

	for (size_t i{ 0 }; i < mXWidth*mYHeight; ++i) {
		if (i%mXWidth == 0 && i>2) {
			cout << '|'<<endl;
		}
		cout << (mExportUniverse.at(i)? '*' : ' ');
	}
	return true;
}

//C++ 17 NECESSARY
std::vector<std::string> filesInPath(std::string folder) {
    std::vector<std::string> files;
    for (auto& file : std::filesystem::directory_iterator(folder)) {
        if (file.is_regular_file()) {
            std::filesystem::path path = file;
            files.push_back(path.string());
        }
    }

    return files;
}

void test(string s) {
	RLE_reader t(s);
	bool b = t.analyzeFile();
	cout << "test : " << s << " result:  " << boolalpha << b << endl << endl;
}

/*
int main() {
	vector<string> testFiles = filesInPath(".\\rle\\");
	for_each(testFiles.begin(), testFiles.end(), [](string s)->void {cout << s << endl; });

	for (string s : testFiles) 
		test(s);
}
*/