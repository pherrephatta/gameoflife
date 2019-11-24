#ifndef RLEREADER_H
#define RLEREADER_H

#include <fstream>
#include <string>
#include <regex>

#include "RLEbuffer.hpp"

using namespace std;
class RLE_reader {

	//to-do eventuel : empecher d'entrer 0 à x ou y
	regex mRgxComments{ "(#)([CcNORr].*)" };
	regex mRgxInitLine{ "x = ([0-9]+), y = ([0-9]+).*" }; //teste la regle pour sa syntaxe (syntaxe:"x = NOMBRE, y = NOMBRE,") , devrait aussi interdire un nombre negatif (on n'accepte que des digits
	regex mRgxRuleFormat{ "^.*[Bb]([0-9]+)[/][Ss]([0-9]+)" };
	regex mRgxLineFormat{ "^.*([bo\\d\\s$!]?)*$" }; //data line format

	vector<bool> mExportUniverse{};//contiguous universe to be eventually exported, if valid
	size_t mXWidth{};
	size_t mYHeight{};
	string mRuleB{};
	string mRuleS{}; //strings pour les regles for now,
	ifstream mRLEfile{};

public:

	RLE_reader() = default;
	RLE_reader(string s);
	~RLE_reader () = default;

	unsigned char ruleB();
	unsigned char ruleS();
	bool analyzeFile();
};

#endif // RLEREADER_H
