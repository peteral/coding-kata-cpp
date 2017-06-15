#include "stdafx.h"
#include "coding_kata.h"
#include <iostream>

using namespace boost;

namespace loc {
	regex multiline("/\\*(.*?(\\n))+.*?\\*/");
	regex singleline("//.*$");
}

int CODINGKATA_API GetLinesOfCode(const string source)
{
	string transformed = regex_replace(source, loc::singleline, "");
	transformed = regex_replace(transformed, loc::multiline, "");

	int loc = 0;
	istringstream iss(transformed);

	for (string line; getline(iss, line); )
	{
		trim(line);

		if (line.length() == 0) continue;

		loc++;
	}

	return loc;
}