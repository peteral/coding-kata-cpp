#include "stdafx.h"
#include "coding_kata.h"

namespace codingkata {

	const set<tuple<string, string>> replacements{
		{ "Ö", "OE" },
		{ "Ä", "AE" },
		{ "Ü", "UE" },
		{ "ö", "OE" },
		{ "ä", "AE" },
		{ "ü", "UE" },
		{ "ß", "SS" },
	};

	const string DATA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	string CODINGKATA_API Rot13(string input)
	{
		string transformed = boost::to_upper_copy(input);

		for (auto it = replacements.begin(); it != replacements.end(); it++)
			transformed = regex_replace(transformed, regex(get<0>(*it)), get<1>(*it));

		string result = "";
		for (auto it = transformed.begin(); it != transformed.end(); it++)
		{
			size_t current = DATA.find(*it);
			if (current == string::npos)
				result += *it;
			else
				result += DATA[(current + 13) % DATA.size()];
		}

		return result;
	}
}