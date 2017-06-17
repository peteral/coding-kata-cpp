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

namespace codingkata {
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

	string CODINGKATA_API Rot13(string input);

	int CODINGKATA_API Mul(int x, int y);

	// templates cannot be exported -> implementation in header file
	template <class T> class BoundedQueue {
	private:
		queue<T> queue;
		int m_size;
		condition_variable cv_not_empty;
		condition_variable cv_not_full;
		mutex mtx;
	public:
		BoundedQueue(int size)
		{
			m_size = size;
		};

		void Enqueue(T element)
		{
			unique_lock<mutex> lck(mtx);
			while (Count() == Size()) cv_not_full.wait(lck);

			queue.push(element);
			cv_not_empty.notify_all();
		};

		T Dequeue() 
		{
			unique_lock<mutex> lck(mtx);
			while (queue.empty()) cv_not_empty.wait(lck);

			auto result = queue.front();
			queue.pop();
			cv_not_full.notify_all();

			return result;
		};

		int Count() 
		{
			return queue.size();
		};

		int Size() 
		{
			return m_size;
		};
	};

}