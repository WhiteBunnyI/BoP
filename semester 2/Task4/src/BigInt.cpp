#include <BigInt.hpp>

BigInt::BigInt(char* num)
{
	m_len = strlen(num);
	std::copy(num, num + m_len + 1, m_str + 1000 - m_len);

}

BigInt& BigInt::operator+=(const BigInt& other)
{
	char temp[1001];
	temp[1000] = '\0';

	int l_min = m_len > other.m_len ? other.m_len : m_len;
	char firstChr_1 = m_str[1000 - m_len];
	char firstChr_2 = other.m_str[1000 - other.m_len];
	int sign_1 = 1;
	int sign_2 = 1;

	if (firstChr_1 == '-') sign_1 = -1;
	if (firstChr_2 == '-') sign_2 = -1;

	char next = 0;
	for (int i = 0; i < l_min; i++)
	{
		char current = (m_str[999 - i] % 48) * sign_1 + (other.m_str[999 - i] % 48) * sign_2 + next;
		next = current / 10;
		current %= 10;
		temp[999 - i] = current < 0 ? -current + 48 : current;
	}
	if (next < 0)
	{
		temp[999 - l_min] = -next + 48;
		temp[999 - l_min - 1] = '-';
		m_len++;
	}
	if(next > 0)
	{
		temp[999 - l_min] = next + 48;
		m_len++;
	}
	std::swap(m_str, temp);
	return *this;

}

BigInt BigInt::operator+(const BigInt& other)
{
	return *this;
}

BigInt& BigInt::operator*=(const BigInt& other)
{
	return *this;

}

BigInt BigInt::operator*(const BigInt& other)
{
	return *this;

}

bool BigInt::operator<(const BigInt& other)
{
	return false;
}

bool BigInt::operator>(const BigInt& other)
{
	return false;

}

bool BigInt::operator==(const BigInt& other)
{
	return false;

}

bool BigInt::operator!=(const BigInt& other)
{
	return false;

}

std::ostream& operator<<(std::ostream& os, BigInt& obj)
{
	char* c = obj.m_str;
	os << (c + 1000 - obj.m_len);
	return os;
}
std::istream& operator>>(std::istream& is, BigInt& obj)
{
	return is;
}



