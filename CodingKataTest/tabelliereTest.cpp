#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\CodingKata\CodingKata.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace CodingKataTest
{		
	// Coding Cata: http://ccd-school.de/coding-dojo/function-katas/csv-tabellieren/
	TEST_CLASS(FizzBuzzTest)
	{
	public:
		
		TEST_METHOD(Returns100Entries)
		{
			Assert::AreEqual((size_t)100, fizzBuzz().size());
		}

		TEST_METHOD(Entry3IsFizz)
		{
			Assert::AreEqual(string("Fizz"), fizzBuzz()[2]);
		}

		TEST_METHOD(Entry6IsFizz)
		{
			Assert::AreEqual(string("Fizz"), fizzBuzz()[5]);
		}

		TEST_METHOD(Entry5IsBuzz)
		{
			Assert::AreEqual(string("Buzz"), fizzBuzz()[4]);
		}

		TEST_METHOD(Entry10IsBuzz)
		{
			Assert::AreEqual(string("Buzz"), fizzBuzz()[9]);
		}

		TEST_METHOD(Entry15IsFizzBuzz)
		{
			Assert::AreEqual(string("FizzBuzz"), fizzBuzz()[14]);
		}
	};
}