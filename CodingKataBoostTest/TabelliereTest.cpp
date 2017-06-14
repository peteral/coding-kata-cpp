      
#include "stdafx.h"
#include "..\CodingKata\CodingKata.h"

BOOST_AUTO_TEST_CASE(HeaderOnly)
{
	ParsedTable table({ "Name;Strasse;Ort;Alter" });

	BOOST_REQUIRE(string("Name|Strasse|Ort|Alter|") == table.getResult()[0]);
}

BOOST_AUTO_TEST_CASE(CompleteTable)
{
	ParsedTable table(
	{ "Name;Strasse;Ort;Alter",
		"Peter Pan;Am Hang 5;12345 Einsam;42",
		"Maria Schmitz;Kölner Straße 45;50123 Köln;43",
		"Paul Meier;Münchener Weg 1;87654 München;65" });

	auto result = table.getResult();

	BOOST_REQUIRE(string("Name         |Strasse         |Ort          |Alter|") == result[0]);
	BOOST_REQUIRE(string("-------------+----------------+-------------+-----+") == result[1]);
	BOOST_REQUIRE(string("Peter Pan    |Am Hang 5       |12345 Einsam |42   |") == result[2]);
	BOOST_REQUIRE(string("Maria Schmitz|Kölner Straße 45|50123 Köln   |43   |") == result[3]);
	BOOST_REQUIRE(string("Paul Meier   |Münchener Weg 1 |87654 München|65   |") == result[4]);
}