// CodingKata.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "CodingKata.h"

using namespace std;
using namespace boost;


vector<string> ParsedTable::getResult()
{
	vector<string> result;

	int index = 0;
	for (auto it = rows.begin(); it != rows.end(); it++, index++)
	{
		result.push_back(formatRow(**it));

		if (index == 0)
			result.push_back(separateHeader());
	}

	return result;
}
ParsedTable::ParsedTable(vector<string> zeilen)
{
	// parse into cells
	char_separator<wchar_t> separator{ L";" };

	for (auto it = zeilen.begin(); it < zeilen.end(); it++) 
	{
		vector<string> *row = new vector<string>();
		
		tokenizer<char_separator<wchar_t>> tok(*it, separator);
		for (auto token = tok.begin(); token != tok.end(); token++)
		{
			(*row).push_back(*token);
		}

		rows.push_back(row);
	}

	// calculate column widths
	for (auto row = rows.begin(); row < rows.end(); row++)
	{
		size_t i = 0;
		for (auto column = (*row)->begin(); column != (*row)->end(); i++, column++)
		{
			while (i >= columnWidth.size()) columnWidth.push_back(0);

			columnWidth[i] = max(columnWidth[i], (*column).size());
		}
	}
}

string ParsedTable::formatRow(vector<string> data)
{
	string result("");
	int i = 0;
	for (auto cell = data.begin(); cell != data.end(); cell++, i++) {
		string formattedCell(*cell);
		auto width = columnWidth[i];

		while (formattedCell.size() < width) formattedCell += " ";

		result += formattedCell + "|";
	}

	return result;
}

string ParsedTable::separateHeader()
{
	string result("");

	for (auto it = columnWidth.begin(); it != columnWidth.end(); it++) {
		for (size_t i = 0; i < *it; i++)
			result += "-";

		result += "+";
	}

	return result;
}

ParsedTable::~ParsedTable()
{
	for (auto it = rows.begin(); it < rows.end(); it++)
		delete *it;
}