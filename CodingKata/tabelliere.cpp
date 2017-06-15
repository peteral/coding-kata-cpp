// CodingKata.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "coding_kata.h"

using namespace std;
using namespace boost;


vector<string> ParsedTable::GetResult()
{
	vector<string> result;

	int index = 0;
	for (auto it = rows.begin(); it != rows.end(); it++, index++)
	{
		result.push_back(FormatRow(**it));

		if (index == 0)
			result.push_back(SeparateHeader());
	}

	return result;
}
ParsedTable::ParsedTable(const vector<string> zeilen)
{
	// parse into cells
	char_separator<wchar_t> separator{ L";" };

	for (auto it = zeilen.begin(); it < zeilen.end(); it++) 
	{
		vector<string> *row = new vector<string>();
		
		tokenizer<char_separator<wchar_t>> tok(*it, separator);
		for (auto token = tok.begin(); token != tok.end(); token++)
			(*row).push_back(*token);

		rows.push_back(row);
	}

	// calculate column widths
	for (auto row = rows.begin(); row < rows.end(); row++)
	{
		size_t i = 0;
		for (auto column = (*row)->begin(); column != (*row)->end(); i++, column++)
		{
			while (i >= column_width.size()) 
				column_width.push_back(0);

			column_width[i] = max(column_width[i], column->size());
		}
	}
}

string ParsedTable::FormatRow(const vector<string> data)
{
	string result("");
	int i = 0;
	for (auto cell = data.begin(); cell != data.end(); cell++, i++) {
		string formattedCell(*cell);

		while (formattedCell.size() < column_width[i]) 
			formattedCell += " ";

		result += formattedCell + "|";
	}

	return result;
}

string ParsedTable::SeparateHeader()
{
	string result("");

	for (auto it = column_width.begin(); it != column_width.end(); it++) {
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