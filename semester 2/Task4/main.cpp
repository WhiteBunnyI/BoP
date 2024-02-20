#include <BigInt.hpp>

int main()
{
	BigInt num1("40000");
	BigInt num2("39999");
	std::cout << num1 << std::endl << num2 << std::endl;
	//std::cout << (num1 < num2) << std::endl;
	//std::cout << (num1 > num2) << std::endl;

	num1 += "-100";
	std::cout << num1 << std::endl;

	num1 *= num2;
	std::cout << num1 << std::endl;

	return 0;
}