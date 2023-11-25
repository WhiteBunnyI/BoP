#include "Functions.h"

namespace func
{
	bool IsPrime(int n)
	{
		for (int i = 2; i < n/2+1; i++)
		{
			if (n % i == 0) return false;
		}

		return true;
	}

	int SumOfDigits(int n)
	{
		int result = 0;
		while (n > 0)
		{
			result += n % 10;
			n /= 10;
		}

		return result;
	}
}
