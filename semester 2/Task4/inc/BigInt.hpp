#pragma once
#include <iostream>

class BigInt
{
	char m_str[1001];
	int m_len;

public:
	BigInt(char* num);

	BigInt& operator+=(BigInt& other);
	BigInt operator+(BigInt& other);

	BigInt& operator*=(BigInt& other);
	BigInt operator*(BigInt& other);

	bool operator<(const BigInt& other);
	bool operator>(const BigInt& other);
	bool operator==(const BigInt& other);
	bool operator!=(const BigInt& other);

	friend std::ostream& operator<<(std::ostream& os, BigInt& obj);
	friend std::istream& operator>>(std::istream& is, BigInt& obj);

	char GetSign() const;
};