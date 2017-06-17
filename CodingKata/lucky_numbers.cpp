#include "stdafx.h"
#include "coding_kata.h"

using namespace std;

namespace codingkata {
	vector<int> GetDigits(int number)
	{
		vector<int> result{};

		int remainder = number;
		while (remainder > 9) {
			int n = remainder / 10;
			remainder = remainder % 10;
			result.push_back(n);
		}

		result.push_back(remainder);

		return result;
	}

	int GetSqSum(int number)
	{
		vector<int> digits = GetDigits(number);
		int result = 0;

		for (auto it = digits.begin(); it != digits.end(); it++)
			result += *it * *it;

		return result;
	}

	bool IsLucky(int number)
	{
		set<int> checked{};

		int sum = GetSqSum(number);

		while (sum != 1 && checked.count(sum) == 0) {
			checked.insert(sum);
			sum = GetSqSum(sum);
		}

		return sum == 1;
	}

	vector<int> CODINGKATA_API LuckyNumbers(int from, int to)
	{
		vector<int> result{};

		for (auto i = from; i <= to; i++)
			if (IsLucky(i))
				result.push_back(i);

		return result;
	}
}