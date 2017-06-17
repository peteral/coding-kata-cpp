#include "stdafx.h"
#include "coding_kata.h"

namespace codingkata {

	int CODINGKATA_API Mul(int x, int y)
	{
		int result = 0;
		int sign = ((x < 0 || y < 0) && (x > 0 || y >0)) ? -1 : 1;
		x = abs(x);
		y = abs(y);

		while (x > 0) {
			if (x % 2 == 1)
				result += y;

			y = 2 * y;
			x = x / 2;
		}

		return sign * result;
	}
}