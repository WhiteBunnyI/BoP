#include <BigInt.hpp>

int main()
{
	BigInt n1("-5001");
	BigInt n2("-5000");
	std::cout << (n1 < n2) << std::endl;
	std::cout << (n2 != n1);
	return 0;
	BigInt num1("123");
	BigInt num2("-200");
	std::cout << num1 << std::endl << num2 << std::endl;
	num1 += num2;
	std::cout << num1;
	return 0;
}