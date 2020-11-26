#include "Tokenizer.h"

vector<string> Tokenizer::split(const string& haystack, const string& seperator,
	bool removeEmptyEntries) {

	vector<string> result;
	size_t start = 0, end;

	do {
		end = haystack.find(seperator, start);

		if (end == string::npos)
			end = haystack.length();

		result.push_back(haystack.substr(start, end - start));
		
		if (removeEmptyEntries)
			start = haystack.find_first_not_of(seperator, end);
		else
			start = seperator.length() + end;

	} while (end != haystack.length());

	return result;
}