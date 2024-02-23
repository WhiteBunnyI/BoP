#include <BigInt.hpp>
#include <vector>

BigInt::BigInt(char* num)
{
	m_len = strlen(num);
	m_str[1000] = '\0';
	std::copy(num, num + m_len + 1, m_str + 1000 - m_len);
	m_len = m_str[1000 - m_len] == '-' ? m_len - 1 : m_len;
}


BigInt& BigInt::operator+=(BigInt& other)
{
	char* dest = &m_str[999];

	char* chr_1 = &m_str[999];
	char* chr_2 = &other.m_str[999];

	char sign_1 = this->GetSign();
	char sign_2 = other.GetSign();

	int l_max = m_len;

	if (m_len < other.m_len)											//5000+    (1)
	{																	// 123     (2)
		l_max = other.m_len;											//наверху у нас всегда самый большой разр€д
		std::swap(chr_1, chr_2);										//
		std::swap(sign_1, sign_2);
	}
	else if (m_len == other.m_len)										//¬ случае, если кол-во разр€дов у нас равны
	{																	//—равниваем числа без знака и ставим наверх наибольшее число 
		for (int i = 0; i < m_len; i++)
		{
			if (m_str[1000 - m_len + i] > other.m_str[1000 - m_len + i]) break;
			if (m_str[1000 - m_len + i] < other.m_str[1000 - m_len + i])
			{
				std::swap(chr_1, chr_2);
				std::swap(sign_1, sign_2);
				break;
			}

		}
	}

	char next = 0;
	for (int i = 0; i < l_max || next; i++)
	{
		char add = next;
		next = 0;							
		if (*chr_1 > 47 && *chr_1 < 58)
		{
			add += (*chr_1 - 48) + 10;
			next--;
		}

		if (*chr_2 > 48 && *chr_2 < 58)
			add += (*chr_2 - 48) * sign_2 * sign_1;			//складываем либо вычитаем в зависимости от знаков чисел

		next += add / 10;
		add %= 10;
		*dest = '0' + add;

		dest--;
		chr_1--;
		chr_2--;
	}

	l_max = strlen(dest);
	m_len = l_max;
	for (int i = 0; i < l_max; i++)							//»збавл€емс€ от лишних символов и нулей в начале и просчитываем кол-во разр€дов в числе
	{
		if (*dest > '0' && *dest <= '9') break;
		dest++;
		m_len--;
	}
	if (sign_1 == -1)										//“.к. 1-ое число у нас было больше 2-ого числа по абсолютному значению, то от сохранит свой знак
	{
		dest--;
		*dest = '-';
	}
	return *this;

}

BigInt BigInt::operator+(BigInt& other)
{
	BigInt temp(*this);
	temp += other;
	return temp;
}

BigInt& BigInt::operator*=(BigInt& other)
{
	char sign_1 = this->GetSign();
	char sign_2 = other.GetSign();
	char* chr_1 = &m_str[999];
	char* chr_2;
	BigInt result("0");
	char str[1001];
	str[1000] = '\0';
	for (int i = 0; i < m_len; i++)
	{	
		char* dest = &str[999];
		chr_2 = &other.m_str[999];

		unsigned int next = 0;
		for (int o = 0; o < i; o++)
		{
			*dest = '0';
			dest--;
		}
		for (int o = 0; o < other.m_len || next; o++)
		{
			unsigned int add = next;
			if (*chr_2 > '0' && *chr_2 <= '9')
			{
				add += (*chr_1 - 48) * (*chr_2 - 48);
			}
			next = add / 10;
			add %= 10;
			*dest = add + 48;
			dest--;
			chr_2--;
		}
		BigInt temp(dest);
		result += temp;
		chr_1--;
	}
	if (sign_1 * sign_2 == -1)
	{
		result.m_str[999 - result.m_len] = '-';
	}
	std::swap(result, *this);
	return *this;
}


BigInt BigInt::operator*(BigInt& other)
{
	BigInt temp(*this);
	temp *= other;
	return temp;

}

bool BigInt::operator<(const BigInt& other)
{
	if (this->GetSign() == -1)
	{
		if (other.GetSign() != -1) return true;
	}
	else if (other.GetSign() == -1)
	{
		if (this->GetSign() != -1) return false;
	}
	else //≈сли оба числа положительные
	{
		if (m_len < other.m_len) return true;		//123 < 5000 - true
		if (m_len > other.m_len) return false;		//5000 < 123 - false

		for (int i = 0; i < m_len; i++)				//5000 < 5001
		{
			if (m_str[1000 - m_len + i] < other.m_str[1000 - m_len + i]) return true;
			if (m_str[1000 - m_len + i] > other.m_str[1000 - m_len + i]) return false;
		}
		return false; //„исла одинаковые
	}

	//≈сли оба числа отрицательные
	if (m_len < other.m_len) return false;		//-123 < -5000 - false
	if (m_len > other.m_len) return true;		//-5000 < -123 - true

	for (int i = 0; i < m_len - 1; i++)				//-5001 < -5000
	{
		if (m_str[1000 - m_len + i] < other.m_str[1000 - m_len + i]) return false;
		if (m_str[1000 - m_len + i] > other.m_str[1000 - m_len + i]) return true;
	}

	return false; //„исла одинаковые
}

bool BigInt::operator>(const BigInt& other)
{
	if (this->GetSign() == -1)
	{
		if (other.GetSign() != -1) return false;
	}
	else if (other.GetSign() == -1)
	{
		if (this->GetSign() != -1) return true;
	}
	else //≈сли оба числа положительные
	{
		if (m_len > other.m_len) return true;		//5000 > 123 - true
		if (m_len < other.m_len) return false;		//123 > 5000 - false

		for (int i = 0; i < m_len; i++)				//5001 > 5000
		{
			if (m_str[1000 - m_len + i] > other.m_str[1000 - m_len + i]) return true;
			if (m_str[1000 - m_len + i] < other.m_str[1000 - m_len + i]) return false;
		}
		return false; //„исла одинаковые
	}

	//≈сли оба числа отрицательные
	if (m_len > other.m_len) return false;		//-5000 > -123 - false
	if (m_len < other.m_len) return true;		//-123 > -5000 - true

	for (int i = 0; i < m_len - 1; i++)				//-5000 > -5001
	{
		if (m_str[1000 - m_len + i] > other.m_str[1000 - m_len + i]) return false;
		if (m_str[1000 - m_len + i] < other.m_str[1000 - m_len + i]) return true;
	}

	return false; //„исла одинаковые
}

bool BigInt::operator==(const BigInt& other)
{
	if (m_len != other.m_len) return false;

	for (int i = 0; i < m_len; i++)				//-5001 == -5001 || 5001 == 5001
	{
		if (m_str[1000 - m_len + i] != other.m_str[1000 - m_len + i]) return false;
	}

	return true; //„исла одинаковые
}

bool BigInt::operator!=(const BigInt& other)
{
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, BigInt& obj)
{
	char* c = obj.m_str;
	if (obj.GetSign() == -1) c--;
	os << (c + 1000 - obj.m_len);
	return os;
}
std::istream& operator>>(std::istream& is, BigInt& obj)
{
	return is;
}

//¬озращ€ет -1 если число отрицательное
//¬озращ€ет 1 если число положительное
char BigInt::GetSign() const
{
	return m_str[999 - m_len] == '-' ? -1 : 1;
}




