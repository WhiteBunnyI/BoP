#include <BigInt.hpp>

BigInt::BigInt(char* num)
{
	m_len = strlen(num);
	std::copy(num, num + m_len + 1, m_str + 1000 - m_len);

}

BigInt& BigInt::operator+=(BigInt& other)
{
	char temp[1001];
	temp[1000] = '\0';

	int l_max = m_len < other.m_len ? other.m_len : m_len;
	char* chr_1 = &m_str[999];
	char* chr_2 = &other.m_str[999];
	char* dest = &temp[999];
	int sign_1 = 1;
	int sign_2 = 1;

	if (m_str[1000 - m_len] == '-') sign_1 = -1;
	if (other.m_str[1000 - other.m_len] == '-') sign_2 = -1;

	char next = 0;
	for (int i = 0; i < l_max; i++)
	{
		*dest = '0';
		if (*chr_1 > 47 && *chr_1 < 58)
		{
			*dest = *chr_1;
		}
		if (*chr_2 > 47 && *chr_2 < 58)
		{

		}

		dest--;
		chr_1--;
		chr_2--;
	}
	if (next < 0)
	{
		temp[999 - l_max] = -next + 48;
		temp[999 - l_max - 1] = '-';
		m_len++;
	}
	if(next > 0)
	{
		temp[999 - l_max] = next + 48;
		m_len++;
	}
	std::swap(m_str, temp);
	return *this;

}

BigInt BigInt::operator+(BigInt& other)
{
	return *this;
}

BigInt& BigInt::operator*=(BigInt& other)
{
	return *this;

}

BigInt BigInt::operator*(BigInt& other)
{
	return *this;

}

bool BigInt::operator<(const BigInt& other)
{
	if (m_str[1000 - m_len] == '-')
	{
		if (other.m_str[1000 - other.m_len] != '-') return true;
	}
	else if (other.m_str[1000 - other.m_len] == '-')
	{
		if (m_str[1000 - m_len] != '-') return false;
	}
	else //Если оба числа положительные
	{
		if (m_len < other.m_len) return true;		//123 < 5000 - true
		if (m_len > other.m_len) return false;		//5000 < 123 - false

		for (int i = 0; i < m_len; i++)				//5000 < 5001
		{
			if (m_str[1000 - m_len + i] < other.m_str[1000 - m_len + i]) return true;
			if (m_str[1000 - m_len + i] > other.m_str[1000 - m_len + i]) return false;
		}
		return false; //Числа одинаковые
	}

	//Если оба числа отрицательные
	if (m_len < other.m_len) return false;		//-123 < -5000 - false
	if (m_len > other.m_len) return true;		//-5000 < -123 - true

	for (int i = 0; i < m_len - 1; i++)				//-5001 < -5000
	{
		if (m_str[1001 - m_len + i] < other.m_str[1001 - m_len + i]) return false;
		if (m_str[1001 - m_len + i] > other.m_str[1001 - m_len + i]) return true;
	}

	return false; //Числа одинаковые
}

bool BigInt::operator>(const BigInt& other)
{
	if (m_str[1000 - m_len] == '-')
	{
		if (other.m_str[1000 - other.m_len] != '-') return false;
	}
	else if (other.m_str[1000 - other.m_len] == '-')
	{
		if (m_str[1000 - m_len] != '-') return true;
	}
	else //Если оба числа положительные
	{
		if (m_len > other.m_len) return true;		//5000 > 123 - true
		if (m_len < other.m_len) return false;		//123 > 5000 - false

		for (int i = 0; i < m_len; i++)				//5001 > 5000
		{
			if (m_str[1000 - m_len + i] > other.m_str[1000 - m_len + i]) return true;
			if (m_str[1000 - m_len + i] < other.m_str[1000 - m_len + i]) return false;
		}
		return false; //Числа одинаковые
	}

	//Если оба числа отрицательные
	if (m_len > other.m_len) return false;		//-5000 > -123 - false
	if (m_len < other.m_len) return true;		//-123 > -5000 - true

	for (int i = 0; i < m_len - 1; i++)				//-5000 > -5001
	{
		if (m_str[1001 - m_len + i] > other.m_str[1001 - m_len + i]) return false;
		if (m_str[1001 - m_len + i] < other.m_str[1001 - m_len + i]) return true;
	}

	return false; //Числа одинаковые
}

bool BigInt::operator==(const BigInt& other)
{
	if (m_len != other.m_len) return false;

	for (int i = 0; i < m_len; i++)				//-5001 == -5001 || 5001 == 5001
	{
		if (m_str[1000 - m_len + i] != other.m_str[1000 - m_len + i]) return false;
	}

	return true; //Числа одинаковые
}

bool BigInt::operator!=(const BigInt& other)
{
	return !(*this == other);
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



