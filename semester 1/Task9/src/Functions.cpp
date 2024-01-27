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

	int GetFirstDigit(int n)
	{
		int temp = 1;

		while (n / temp > 9)
		{
			temp *= 10;
		}

		return n / temp;
	}

	bool IsHaveEvenDigit(int n)
	{
		while (n > 0)
		{
			if ((n % 10) % 2 == 0) return true;
			n /= 10;
		}
		return false;
	}

	bool isHaveDigitInNum(int num, int digit)
	{
		while (num > 0)
		{
			if (num % 10 == digit) return true;
			num /= 10;
		}

		return false;
	}
}
