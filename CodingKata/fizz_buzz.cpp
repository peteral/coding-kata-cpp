#include "stdafx.h"
#include "coding_kata.h"

const string FIZZ = string("Fizz");
const string BUZZ = string("Buzz");
const string FIZZBUZZ = FIZZ + BUZZ;

string ConvertNumber(int number)
{
	if (number % 3 == 0 && number % 5 == 0)
		return FIZZBUZZ;

	if (number % 3 == 0)
		return FIZZ;

	if (number % 5 == 0)
		return BUZZ;

	return to_string(number);
}

vector<string> CODINGKATA_API FizzBuzz()
{
	vector<string> result {};

	for (int i = 1; i <= 100; i++) {
		result.push_back(ConvertNumber(i));
	}

	return result;
}