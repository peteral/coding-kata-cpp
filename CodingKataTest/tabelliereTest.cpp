#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\CodingKata\CodingKata.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace CodingKataTest
{		
	TEST_CLASS(TabelliereTest)
	{
	public:
		
		TEST_METHOD(HeaderOnlyIsCorrect)
		{
			Assert::AreEqual(string("Name|Strasse|Ort|Alter|"), tabelliere(vector<string> {"Name;Strasse;Ort;Alter"})[0]);
		}

	};
}