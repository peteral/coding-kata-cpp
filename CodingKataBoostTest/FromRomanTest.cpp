      
#include "stdafx.h"
#include "..\CodingKata\CodingKata.h"

using namespace std;

namespace bdata = boost::unit_test::data;

namespace roman {
	typedef struct {
		int arabic;
		string roman;
	} dataset_entry;

	vector<dataset_entry> entries{
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
		BOOST_TEST(entries[index].arabic == fromRomanNumerals(entries[index].roman));
	}

	bool correctSyntaxErrorMessage(const roman_exception& ex)
	{
		BOOST_CHECK_EQUAL(ex.message, "Invalid character: [ ]");
		return true;
	}

	BOOST_AUTO_TEST_CASE(SyntaxError)
	{
		BOOST_CHECK_EXCEPTION(fromRomanNumerals("I X"), roman_exception, correctSyntaxErrorMessage);
	}

	bool correctSemanticsErrorMessage(const roman_exception& ex)
	{
		BOOST_CHECK_EQUAL(ex.message, "Invalid character [C] before [I]");
		return true;
	}

	BOOST_AUTO_TEST_CASE(SemanticsError)
	{
		BOOST_CHECK_EXCEPTION(fromRomanNumerals("IC"), roman_exception, correctSemanticsErrorMessage);
	}
}