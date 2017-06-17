      
#include "stdafx.h"

#include "..\CodingKata\coding_kata.h"

using namespace std;
using namespace boost::posix_time;
using namespace boost::gregorian;
using namespace codingkata;

namespace bdata = boost::unit_test::data;

namespace followup {
	const ptime NOW(date(2017, Jun, 15), hours(20) + minutes(4));

	typedef struct {
		ptime now;
		string email;
		ptime expected;
	} DatasetEntries;

	vector<DatasetEntries> entries {
		{ NOW, "7days@followup.cc",				ptime(date(2017, Jun, 22), hours(20) + minutes(4)) },
		{ NOW, "12hours@followup.cc",			ptime(date(2017, Jun, 16), hours(8) + minutes(4)) },
		{ NOW, "aug15-9am@followup.cc",			ptime(date(2017, Aug, 15), hours(9)) },
		{ NOW, "1week3days5hours@followup.cc",	ptime(date(2017, Jun, 26), hours(1) + minutes(4)) },
	};

	BOOST_DATA_TEST_CASE(MailFollowup,
		bdata::xrange(entries.size()),
		index)
	{
		BOOST_CHECK_EQUAL(entries[index].expected, FollowupTime(entries[index].now, entries[index].email));
	}

}