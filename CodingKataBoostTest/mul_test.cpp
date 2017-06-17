      
#include "stdafx.h"
#include "../CodingKata/coding_kata.h"
using namespace std;
using namespace codingkata;

namespace bdata = boost::unit_test::data;

namespace mul {
	vector<tuple<int, int, int>> entries{
		{ 47, 42, 1974 },
		{ -47, -42, 1974 },
		{ -47, 42, -1974 },
		{ 47, -42, -1974 },
		{ 1, 1, 1 },
		{ 0, 10, 0 },
		{ 23, 0, 0 },
	};

	BOOST_DATA_TEST_CASE(MulTest,
		bdata::xrange(entries.size()),
		index)
	{
		int x = get<0>(entries[index]);
		int y = get<1>(entries[index]);
		int expected = get<2>(entries[index]);

		BOOST_CHECK_EQUAL(x * y, Mul(x, y));
	}
}
