// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the CODINGKATA_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// CODINGKATA_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef CODINGKATA_EXPORTS
#define CODINGKATA_API __declspec(dllexport)
#else
#define CODINGKATA_API __declspec(dllimport)
#endif

#include "stdafx.h"

using namespace std;
using namespace boost::posix_time;

class CODINGKATA_API ParsedTable
{
private:
	vector<vector<string>*> rows;
	vector<size_t> column_width;
	string SeparateHeader();
	string FormatRow(const vector<string>);
public:
	ParsedTable(const vector<string>);
	~ParsedTable();

	vector<string> GetResult();
};

vector<string> CODINGKATA_API FizzBuzz();

class CODINGKATA_API RomanException {
public:
	RomanException(const string m) { message = m; };
	string message;
};

int CODINGKATA_API FromRomanNumerals(const string roman);

vector<int> CODINGKATA_API LuckyNumbers(int from, int to);

int CODINGKATA_API GetLinesOfCode(const string source);

ptime CODINGKATA_API FollowupTime(ptime now, string email);