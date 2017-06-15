#include "stdafx.h"
#include "CodingKata.h"

using namespace std;

map<char, int> roman_literals = {
	{'I', 1},
	{ 'V', 5 },
	{ 'X', 10 },
	{ 'L', 50 },
	{ 'C', 100 },
	{ 'D', 500 },
	{ 'M', 1000 },
};

int CODINGKATA_API fromRomanNumerals(string roman)
{
	int result = 0;

	for (auto it = roman.begin(); it != roman.end(); it++) {
		bool addition = true;

		// subtraction only when not last character
		if (it + 1 != roman.end()) {
			if (*it == 'I' && (*(it + 1) == 'V' || *(it + 1) == 'X')) addition = false;
			if (*it == 'X' && (*(it + 1) == 'L' || *(it + 1) == 'C')) addition = false;
			if (*it == 'C' && (*(it + 1) == 'D' || *(it + 1) == 'M')) addition = false;
		}

		if (addition)
			result += roman_literals[*it];
		else
			result -= roman_literals[*it];
	}
		

	return result;
}
