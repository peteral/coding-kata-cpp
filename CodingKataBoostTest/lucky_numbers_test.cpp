      
#include "stdafx.h"
#include "..\CodingKata\coding_kata.h"

using namespace std; 
using namespace codingkata;

namespace bdata = boost::unit_test::data;

namespace lucky {
	typedef struct {
		int from;
		int to;
		vector<int> expected;
	} DatasetEntries;

	vector<tuple<int, int, vector<int>>> entries{
		{ 1, 1, { 1 } },
		{ 1, 10, { 1 , 10} },
		{ 10, 20, { 10, 13 } },
	};

	BOOST_DATA_TEST_CASE(LuckyNumbersTest,
		bdata::xrange(entries.size()),
		index)
	{
		int from = get<0>(entries[index]);
		int to = get<1>(entries[index]);
		vector<int> expected = get<2>(entries[index]);
		vector<int> result = LuckyNumbers(from, to);

		BOOST_CHECK_EQUAL_COLLECTIONS(
			expected.begin(), expected.end(),
			result.begin(), result.end()
			);
	}

	bool CorrectSyntaxErrorMessage(const RomanException& ex)
	{
		BOOST_CHECK_EQUAL(ex.message, "Invalid character: [ ]");
		return true;
	}

	BOOST_AUTO_TEST_CASE(SyntaxError)
	{
		BOOST_CHECK_EXCEPTION(FromRomanNumerals("I X"), RomanException, CorrectSyntaxErrorMessage);
	}

	bool CorrectSemanticsErrorMessage(const RomanException& ex)
	{
		BOOST_CHECK_EQUAL(ex.message, "Invalid character [I] before [C]");
		return true;
	}

	BOOST_AUTO_TEST_CASE(SemanticsError)
	{
		BOOST_CHECK_EXCEPTION(FromRomanNumerals("IC"), RomanException, CorrectSemanticsErrorMessage);
	}
}
