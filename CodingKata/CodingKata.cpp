// CodingKata.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "CodingKata.h"

using namespace std;
using namespace boost::lambda;
using namespace boost;

vector<vector<string>*> parse(vector<string> zeilen)
{
	vector<vector<string>*> result {};
	char_separator<wchar_t> separator{ L";" };

	for (auto it = zeilen.begin(); it < zeilen.end(); it++) 
	{
		vector<string> *row = new vector<string>();
		
		tokenizer<char_separator<wchar_t>> tok(*it, separator);
		for (auto token = tok.begin(); token != tok.end(); token++)
		{
			(*row).push_back(*token);
		}

		result.push_back(row);
	}

	return result;
}

vector<size_t> calculateColumnWidths(vector<vector<string>*> tabelle)
{
	vector<size_t> result;

	for (auto row = tabelle.begin(); row < tabelle.end(); row++) 
	{
		size_t i = 0;
		for (auto column = (**row).begin(); column != (**row).end(); i++, column++)
		{
			while (i >= result.size()) result.push_back(0);

			result[i] = max(result[i], (*column).size());
		}
	}

	return result;
}

string formatRow(vector<string> data, vector<size_t> columnWidth)
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

string separateHeader(vector<size_t> columnWidth)
{
	string result("");

	for (auto it = columnWidth.begin(); it != columnWidth.end(); it++) {
		for (size_t i = 0; i < *it; i++)
			result += "-";

		result += "+";
	}

	return result;
}

CODINGKATA_API vector<string> tabelliere(vector<string> zeilen)
{
	vector<vector<string>*> tabelle = parse(zeilen);
	vector<size_t> columnWidth = calculateColumnWidths(tabelle);

	vector<string> result;

	int index = 0;
	for (auto it = tabelle.begin(); it != tabelle.end(); it++, index++)
	{
		result.push_back(formatRow(**it, columnWidth));

		if (index == 0)
			result.push_back(separateHeader(columnWidth));
	}

	for (auto it = tabelle.begin(); it != tabelle.end(); it++) delete *it;

	return result;
}
