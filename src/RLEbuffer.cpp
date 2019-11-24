#include "RLEbuffer.hpp"
#include <iostream>

///test

using namespace std;

RLEbuffer::RLEbuffer(string s, size_t maxsize)
	:mBufferSize{ 0 }, mExtractedUniverse{}, mMaxSize{ maxsize }, mCurrLine{s} {
}

bool RLEbuffer::verifyCoherence() {
	return mExtractedUniverse.size() > mMaxSize ? false : true;
}

bool RLEbuffer::analyzeDataString() {
	for (char c : mCurrLine) {

		if (c == 'b' || c == 'o') {
			mBufferSize = (mBufferSize == 0) ? 1 : mBufferSize; // si on a rien dans le buffer size, il est de 1 (avec l'état selon b ou o). pratique pour lire par ex: obo24b24o
			for (size_t i{ 0 }; i < mBufferSize; ++i) {
				mExtractedUniverse.push_back(c == 'o' ? true : false); // b = vivant, 0 = mort
			}
			if (!verifyCoherence()) { //si on fail le test d
				return false;
			}
			mBufferSize = 0;
		}
		else if (isdigit(c)) {
			mBufferSize *= 10; //on decale le chiffre actuel dans le buffer a gauche d'une coche (donc *10)
			mBufferSize += c - '0'; //on ajoute a lextreme droite du buffer de chiffre le dernier. ex: 10, 10_, 104.
			if (!verifyCoherence()) { return false; }
		}
		else if (c == '!' && mBufferSize == 0) { //si on croise un !, le tampon doit etre vide (ex: pas de bobo123!)
			mDone = true;
		}
		else{
			if (mDone&&(c == '#' || c== ' ' || c =='\n')) //si on a atteint la fin des données et que le prochain char est un debut de commentaire ou "rien"
			{
				return true;
			}
			cout << "Buffer: Irregulatity in char reading";
			return false;
		}

	}
	//si on se rend ici, a on évalué chaque char de la chaine
	size_t valBeforeDollar = mBufferSize; //tldr: nb of dead lines to insert after current line. on garde en memoire la possible valoir numerique devant le signe de piasse; celui ci nous indique le nombre de lignes mortes a inserer apres avoir rempli le restant de la ligne actuelle avec des morts (si applicable).
	
	mBufferSize = mMaxSize - mExtractedUniverse.size();
	if (mBufferSize != 0) { //s'il reste des espaces a remplir, on le remplit de mort
		for (size_t i{ 0 }; i < mBufferSize; ++i) {
			mExtractedUniverse.push_back(false); //
		}
	}

	for (size_t i{ 0 }; i < (valBeforeDollar==0?0:valBeforeDollar-1); ++i) {//1(implicit) newline = 1 empty line,  2 retour de ligne = 1 ligne vide, 3 = 2 lignes vides
		for (size_t j{ 0 }; j < mMaxSize; ++j) {
			mExtractedUniverse.push_back(false); //pour chaque signe de piasse, on push back une ligne de x-longueur de morts
		}
	}

	return true;
}



