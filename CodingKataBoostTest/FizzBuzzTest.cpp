      
#include "stdafx.h"
#include "..\CodingKata\CodingKata.h"

BOOST_AUTO_TEST_CASE(Returns100Entries)
{
	BOOST_REQUIRE((size_t)100 == fizzBuzz().size());
}

BOOST_AUTO_TEST_CASE(Entry3IsFizz)
{
	BOOST_REQUIRE(string("Fizz") == fizzBuzz()[2]);
}

BOOST_AUTO_TEST_CASE(Entry6IsFizz)
{
	BOOST_REQUIRE(string("Fizz") == fizzBuzz()[5]);
}

BOOST_AUTO_TEST_CASE(Entry5IsBuzz)
{
	BOOST_REQUIRE(string("Buzz") == fizzBuzz()[4]);
}

BOOST_AUTO_TEST_CASE(Entry10IsBuzz)
{
	BOOST_REQUIRE(string("Buzz") == fizzBuzz()[9]);
}

BOOST_AUTO_TEST_CASE(Entry15IsFizzBuzz)
{
	BOOST_REQUIRE(string("FizzBuzz") == fizzBuzz()[14]);
}