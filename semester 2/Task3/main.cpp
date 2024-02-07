#include <cString.hpp>
#include <iostream>

int main()
{
	my::String str("Hello");
	my::String str1("World");
	std::cout << str << std::endl << str1 << std::endl;

	my::String str2 = str;
	std::cout << str2 << std::endl;

	str2 += str1;
	std::cout << str2 << std::endl;

	my::String str3 = str2 + " " + str;
	std::cout << str3 << std::endl;
	str3 += " AbcD";
	std::cout << str3 << std::endl;

	my::String str4(0);
	std::cin >> str4;
	std::cout << str4 << std::endl;

	std::cout << str.Find('l') << std::endl;
	std::cout << str.Length() << std::endl;
	std::cout << str.C_str() << std::endl;
	std::cout << str.At(4) << std::endl;


}