#include <BigInt.hpp>

int main()
{
	std::cout << (-3 % 10);
	return 0;
	BigInt num1("123");
	BigInt num2("-200");
	std::cout << num1 << std::endl << num2 << std::endl;
	num1 += num2;
	std::cout << num1;
	return 0;
}