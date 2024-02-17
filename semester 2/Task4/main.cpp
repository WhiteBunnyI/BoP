#include <BigInt.hpp>

int main()
{
	BigInt num1("12559");
	BigInt num2("34539");
	std::cout << num1 << std::endl << num2 << std::endl;
	std::cout << (num1 < num2) << std::endl;
	std::cout << (num1 > num2) << std::endl;

	num1 += num2;
	std::cout << num1;
	return 0;
}