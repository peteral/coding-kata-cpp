      
#include "stdafx.h"
#include "..\CodingKata\coding_kata.h"

using namespace std;

namespace bdata = boost::unit_test::data;

namespace roman {
	typedef struct {
		int arabic;
		string roman;
	} DatasetEntries;

	vector<DatasetEntries> entries{
		{ 1, "I" },
		{ 2, "II" },
		{ 4, "IV" },
		{ 5, "V" },
		{ 9, "IX" },
		{ 42, "XLII" },
		{ 99, "XCIX" },
		{ 2013, "MMXIII" }
	};

	BOOST_DATA_TEST_CASE(FromRomanTest,
		bdata::xrange(entries.size()),
		index)
	{
		BOOST_TEST(entries[index].arabic == FromRomanNumerals(entries[index].roman));
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