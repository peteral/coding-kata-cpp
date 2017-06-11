#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\CodingKata\CodingKata.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace CodingKataTest
{		
	// Coding Cata: http://ccd-school.de/coding-dojo/function-katas/csv-tabellieren/
	TEST_CLASS(TabelliereTest)
	{
	public:
		
		TEST_METHOD(HeaderOnly)
		{
			ParsedTable table({"Name;Strasse;Ort;Alter"});

			Assert::AreEqual(string("Name|Strasse|Ort|Alter|"), table.getResult()[0]);
		}

		TEST_METHOD(CompleteTable)
		{
			ParsedTable table(
				{"Name;Strasse;Ort;Alter",
				"Peter Pan;Am Hang 5;12345 Einsam;42",
				"Maria Schmitz;K�lner Stra�e 45;50123 K�ln;43",
				"Paul Meier;M�nchener Weg 1;87654 M�nchen;65"});

			auto result = table.getResult();

			Assert::AreEqual(string("Name         |Strasse         |Ort          |Alter|"), result[0]);
			Assert::AreEqual(string("-------------+----------------+-------------+-----+"), result[1]);
			Assert::AreEqual(string("Peter Pan    |Am Hang 5       |12345 Einsam |42   |"), result[2]);
			Assert::AreEqual(string("Maria Schmitz|K�lner Stra�e 45|50123 K�ln   |43   |"), result[3]);
			Assert::AreEqual(string("Paul Meier   |M�nchener Weg 1 |87654 M�nchen|65   |"), result[4]);
		}
	};
}