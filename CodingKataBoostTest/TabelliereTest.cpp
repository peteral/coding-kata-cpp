      
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
		"Maria Schmitz;K�lner Stra�e 45;50123 K�ln;43",
		"Paul Meier;M�nchener Weg 1;87654 M�nchen;65" });

	auto result = table.getResult();

	BOOST_REQUIRE(string("Name         |Strasse         |Ort          |Alter|") == result[0]);
	BOOST_REQUIRE(string("-------------+----------------+-------------+-----+") == result[1]);
	BOOST_REQUIRE(string("Peter Pan    |Am Hang 5       |12345 Einsam |42   |") == result[2]);
	BOOST_REQUIRE(string("Maria Schmitz|K�lner Stra�e 45|50123 K�ln   |43   |") == result[3]);
	BOOST_REQUIRE(string("Paul Meier   |M�nchener Weg 1 |87654 M�nchen|65   |") == result[4]);
}