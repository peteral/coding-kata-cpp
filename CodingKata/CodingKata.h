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

using namespace std;

class CODINGKATA_API ParsedTable
{
private:
	vector<vector<string>*> rows;
	vector<size_t> columnWidth;
	string separateHeader();
	string formatRow(vector<string>);
public:
	ParsedTable(vector<string>);
	~ParsedTable();

	vector<string> getResult();
};

vector<string> CODINGKATA_API fizzBuzz();