#include <BigInt.hpp>

int main()
{
	BigInt num1("410410410410410410410410410410410410410");
	BigInt num2("-39999999999999999999999999999999999999");
	BigInt sum("370410410410410410410410410410410410411");
	BigInt mul("-16416416416416416416416416416416416415989589589589589589589589589589589589590");
	std::cout << num1 << std::endl << num2 << std::endl;
	//std::cout << (num1 < num2) << std::endl;
	//std::cout << (num1 > num2) << std::endl;

	std::cout << (num1 + num2) << std::endl;
	std::cout << "Is the sum correct? " << std::endl;
	std::cout << (((num1 + num2) == sum) ? "Correct" : "Wrong") << std::endl;

	std::cout << (num1 * num2) << std::endl;
	std::cout << "Is the multiplication correct? " << std::endl;
	std::cout << (((num1 * num2) == mul) ? "Correct" : "Wrong") << std::endl;

	return 0;
}