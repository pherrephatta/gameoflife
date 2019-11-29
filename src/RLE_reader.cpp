#include "RLE_reader.hpp"
#include <iostream>
RLE_reader::RLE_reader(string s) 
	:mRLEfile{ s }, fileName{s}{
	
	if (!mRLEfile.is_open()) { cout << fileName  << ":Cannot open RLE file" << endl; }

}

unsigned char RLE_reader::ruleB() {
	unsigned char ruleB(NULL);
	for (char c : mRuleB) {
		size_t bitToSet = c-'0';
		ruleB ^= (1 << (bitToSet - 1));
	}
	return ruleB;
}

unsigned char RLE_reader::ruleS() {
	unsigned char ruleS(NULL);
	for (char c : mRuleS) {
		size_t bitToSet = c - '0';
		ruleS ^= (1<<(bitToSet-1));
	}
	return ruleS;
}

bool RLE_reader::analyzeFile() { //TO DO : BREAK IT DOWN. currently takes way too long to reject the largeRLE file
	smatch s;
	string line;
	bool inComments{ true };
	bool endOfFile{ false };
	std::fstream in(fileName, std::fstream::ate | std::fstream::binary);
	while (mRLEfile.is_open()) {
		while (mRLEfile.good() && inComments) {

			getline(mRLEfile, line);
			inComments = regex_match(line, s, mRgxComments);
			if (!inComments) {
				regex_match(line, s, mRgxInitLine);
				if (s.length() > 0) {
					mXWidth = stoi(s[1].str());
					mYHeight = stoi(s[2].str());
					if (mXWidth <1 || mYHeight <1) {
						cout << " : invalid size parameters"  << endl; //will likely never be reached b/c the regex makes sure there are no '-' in the line
						return false;
					}
					regex_match(line, s, mRgxRuleFormat);//validation optionnelle de la regle
					if (s.length() > 0) {
						mRuleB = s[1].str();
						mRuleS = s[2].str();
					//we can "exit" the header with all necessary info
					}
					else{
						cout << fileName  << " : invalid or inexistent rule format" << endl;
					}
				}
				else {
					cout << fileName  << " : Empty file, invalid comment, syntaxically invalid/inexistent initilization line, or invalid x y parameters" << endl;
					cout << fileName  << " : Encountered error : " << line << endl;
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
				cout << fileName  << " : Pattern overflow" << endl;
				return false;
			}
			else if (b.analyzeDataString()) {
				vector<bool> freshUniverse = b.ExtractedUniverse();
				mExportUniverse.insert(mExportUniverse.end(), freshUniverse.begin(), freshUniverse.end());
				endOfFile = b.done();
			}
			else {
				cout << fileName  << ": incoherence in data (x overflow most likely)";
				return false;
			}
		}
		mRLEfile.close();
	}

		return true;
}
