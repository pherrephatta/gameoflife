#ifndef RLEBUFFER_H
#define RLEBUFFER_H

#include <vector>
#include <string>

using namespace std;

class RLEbuffer {

	size_t mBufferSize;
	vector<bool> mExtractedUniverse;//to be sent to RLE reader if valid
	const size_t mMaxSize; //max X size/width
	const string mCurrLine;
	bool mDone{ false }; // '!' char encountered

public:
	RLEbuffer(string s, size_t maxsize);
	~RLEbuffer () = default; 
	vector<bool> ExtractedUniverse() { return mExtractedUniverse; } //get universe extracted from a class. Ideal to use verifyCoherence before
	bool verifyCoherence();
	bool done(){ return (verifyCoherence() && mDone); }
	bool analyzeDataString();
};

#endif // RLEBUFFER_H