#include "stdafx.h"
#include "coding_kata.h"


using namespace boost::posix_time;
using namespace boost::gregorian;

namespace codingkata {

	namespace followup {
		regex cut_suffix("@.*$");
		regex find_days("([0-9]*)days?");
		regex find_hours("([0-9]*)hours?");
		regex find_weeks("([0-9]*)weeks?");
		regex find_time("([a-z]*)([0-9]*)-([0-9]*)([ap]m)");
		map<string, int> months{
			{ "jan", Jan },
			{ "feb", Feb },
			{ "mar", Mar },
			{ "apr", Apr },
			{ "may", May },
			{ "jun", Jun },
			{ "jul", Jul },
			{ "aug", Aug },
			{ "sep", Sep },
			{ "oct", Oct },
			{ "nov", Nov },
			{ "dec", Dec },
		};

		ptime GetTime(ptime ref, string month, string day, string hour, string ampm)
		{
			ptime result(date(ref.date().year(), months[month], stoi(day)));
			result += hours(stoi(hour));
			if (ampm == "pm")
				result += hours(12);

			return result;
		}
	}

	using namespace followup;

	ptime CODINGKATA_API FollowupTime(ptime now, string email)
	{
		string prefix = regex_replace(email, cut_suffix, "");
		ptime result = now;
		smatch matcher;

		if (regex_search(prefix, matcher, find_days))	result += days(stoi(matcher[1]));
		if (regex_search(prefix, matcher, find_hours))	result += hours(stoi(matcher[1]));
		if (regex_search(prefix, matcher, find_weeks))	result += weeks(stoi(matcher[1]));
		if (regex_search(prefix, matcher, find_time))	result = GetTime(now, matcher[1], matcher[2], matcher[3], matcher[4]);

		return result;
	}
}