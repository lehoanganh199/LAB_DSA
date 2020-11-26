#ifndef TOKENIZER_H_
#define TOKENIZER_H_

#include <vector>
#include <string>

using namespace std;

class Tokenizer {
public:
	static vector<string> split(const string& haystack, const string& seperator = " ",
		bool removeEmptyEntries = false);
};

#endif