#include "stdafx.h"
#include "CodingKata.h"

using namespace std;

map<char, int> roman_literals = {
	{ 'I', 1},
	{ 'V', 5 },
	{ 'X', 10 },
	{ 'L', 50 },
	{ 'C', 100 },
	{ 'D', 500 },
	{ 'M', 1000 },
};

map<char, set<char>> valid_predecessors = {
	{ 'I', { 'I', 'V', 'X', 'L', 'C', 'D', 'M' } },
	{ 'V', { 'I', 'X', 'L', 'C', 'D', 'M' } },
	{ 'X', { 'I', 'X', 'L', 'C', 'D', 'M' } },
	{ 'L', { 'X', 'C', 'D', 'M' } },
	{ 'C', { 'X', 'C', 'D', 'M' } },
	{ 'D', { 'C', 'M' } },
	{ 'M', { 'C', 'M' } },
};

bool romanIsAddition(string::iterator it, string::iterator end)
{
	bool addition = true;

	// subtraction only when not last character
	if (it + 1 != end) {
		if (*it == 'I' && (*(it + 1) == 'V' || *(it + 1) == 'X')) addition = false;
		if (*it == 'X' && (*(it + 1) == 'L' || *(it + 1) == 'C')) addition = false;
		if (*it == 'C' && (*(it + 1) == 'D' || *(it + 1) == 'M')) addition = false;
	}

	return addition;
}

void assertValidSyntax(string::iterator it)
{
	if (roman_literals.count(*it) == 0) {
		string message = "Invalid character: [";
		message += *it;
		message += "]";

		throw roman_exception(message);
	}
}

void assertValidSemantics(string::iterator it, string::iterator first)
{
	if (it == first) return;

	set<char> valid = valid_predecessors[*it];
	if (valid.count(*(it - 1)) == 0) {
		string message = "Invalid character [";
		message += *it;
		message += "] before [";
		message += *(it - 1);
		message += "]";

		throw roman_exception(message);
	}
}

int CODINGKATA_API fromRomanNumerals(string roman)
{
	int result = 0;

	for (auto it = roman.begin(); it != roman.end(); it++) {
		assertValidSyntax(it);
		assertValidSemantics(it, roman.begin());

		if (romanIsAddition(it, roman.end()))
			result += roman_literals[*it];
		else
			result -= roman_literals[*it];
	}

	return result;
}
