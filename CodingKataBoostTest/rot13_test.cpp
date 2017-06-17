      
#include "stdafx.h"
#include "../CodingKata/coding_kata.h"

using namespace codingkata;

BOOST_AUTO_TEST_CASE( Rot13Test )  
{
	BOOST_CHECK_EQUAL("URYYB, JBEYQ", Rot13("Hello, World"));
}

BOOST_AUTO_TEST_CASE(Rot13UmlautTest)
{
	BOOST_CHECK_EQUAL("URYYBR, JBREYQ", Rot13("Hellö, Wörld"));
}
