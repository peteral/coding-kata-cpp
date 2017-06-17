      
#include "stdafx.h"
#include "..\CodingKata\coding_kata.h"

namespace bdata = boost::unit_test::data;
using namespace std;
using namespace codingkata;

namespace fizzbuzz {
	BOOST_AUTO_TEST_CASE(Returns100Entries)
	{
		BOOST_TEST((size_t)100 == FizzBuzz().size());
	}

	typedef struct {
		int index;
		string expected;
	} DatasetEntry;

	vector<DatasetEntry> entries{
			{ 2, "Fizz" },
			{ 5, "Fizz" },
			{ 4, "Buzz" },
			{ 9, "Buzz" },
			{ 14, "FizzBuzz" },
			{ 1, "2" }
	};

	BOOST_DATA_TEST_CASE(CheckEntries,
		bdata::xrange(entries.size()),
		index)
	{
		BOOST_TEST(entries[index].expected == FizzBuzz()[entries[index].index]);
	}
}