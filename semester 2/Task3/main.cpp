#include <cString.hpp>
#include <iostream>

int main()
{
	my::String s("bla");
	my::String ss("abc");
	s += ss;
	std::cout << s;
	return 0;

	my::String str("Hello");
	my::String str1("WorldkdfhkdfhgkdfhgkdjfhgkdfhgkjdhfkgjhdfjkghdfkhgeriuhjkvdfWorldkdfhkdfhgkdfhgkdjfhgkdfhgkjdhfkgjhdfjkghdfkhgeriuhjkvdf");
	std::cout << str << std::endl;
	std::cout << str1 << std::endl;

	my::String str2 = str;
	std::cout << str2 << std::endl;

	str2 += str1;
	std::cout << str2 << std::endl;

	my::String str3 = str2 + " " + str;
	std::cout << str3 << std::endl;
	str3 += " AbcD";
	std::cout << str3 << std::endl;

	my::String str4("");
	std::cin >> str4;
	std::cout << str4 << std::endl;

	std::cout << str.Find('l') << std::endl;
	std::cout << str.Length() << std::endl;
	std::cout << str.C_str() << std::endl;
	std::cout << str.At(4) << std::endl;

	my::String test("Textdkjfsfgsdgsdgsfgsfgsfgdfgf");

	test += '!';
	std::cout << test << std::endl;

}