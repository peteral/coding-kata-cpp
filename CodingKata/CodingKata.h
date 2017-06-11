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

CODINGKATA_API std::vector<std::string> tabelliere(std::vector<std::string>);
