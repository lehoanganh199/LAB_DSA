#include "Tokenizer.h"

vector<string> Tokenizer::split(const string& haystack, const string& separator,
	bool removeEmptyEntries) {

	vector<string> result;
	size_t start = 0, end;

	do {
		end = haystack.find(separator, start);

		if (end == string::npos)
			end = haystack.length();

		result.push_back(haystack.substr(start, end - start));
		
		if (removeEmptyEntries)
			start = haystack.find_first_not_of(separator, end);
		else
			start = separator.length() + end;

	} while (end != haystack.length());

	return result;
}
