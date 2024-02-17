#include <BigInt.hpp>

BigInt::BigInt(char* num)
{
	m_len = strlen(num);
	m_str[1000] = '\0';
	std::copy(num, num + m_len + 1, m_str + 1000 - m_len);
	m_len = m_str[1000 - m_len] == '-' ? m_len - 1 : m_len;
}

BigInt& BigInt::operator+=(BigInt& other)
{
	char temp[1001];
	temp[1000] = '\0';
	char* dest = &temp[999];

	char* chr_1 = &m_str[999];
	char* chr_2 = &other.m_str[999];

	char sign_1 = this->GetSign();
	char sign_2 = other.GetSign();

	int l_max = m_len;

	if (m_len < other.m_len)											//5000+    (1)
	{																	// 123     (2)
		l_max = other.m_len;											//������� � ��� ������ ����� ������� ������
		std::swap(chr_1, chr_2);										//
		std::swap(sign_1, sign_2);
	}
	else if (m_len == other.m_len)										//� ������, ���� ���-�� �������� � ��� �����
	{																	//���������� ����� ��� ����� � ������ ������ ���������� ����� 
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
		next = -1;							//-1 �.�. �������� +10

		add += (*chr_1 - 48) + 10;

		if (*chr_2 > 48 && *chr_2 < 58)
			add += (*chr_2 - 48) * sign_2 * sign_1;			//���������� ���� �������� � ����������� �� ������ �����

		next += add / 10;
		add %= 10;
		*dest = '0' + add;

		dest--;
		chr_1--;
		chr_2--;
	}

	l_max = strlen(dest);
	for (int i = 0; i < l_max; i++)							//����������� �� ������ �������� � ����� � ������ � ������������ ���-�� �������� � �����
	{
		if (*dest > '0' && *dest <= '9') break;
		dest++;
		l_max--;
	}
	if (sign_1 == -1)										//�.�. 1 ����� � ��� ���� ������ 2 ����� �� ����������� ��������, �� �� �������� ���� ����
	{
		dest--;
		*dest = '-';
	}

	m_len = l_max;
	std::swap(m_str, temp);
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
	return *this;

}

BigInt BigInt::operator*(BigInt& other)
{
	return *this;

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
	else //���� ��� ����� �������������
	{
		if (m_len < other.m_len) return true;		//123 < 5000 - true
		if (m_len > other.m_len) return false;		//5000 < 123 - false

		for (int i = 0; i < m_len; i++)				//5000 < 5001
		{
			if (m_str[1000 - m_len + i] < other.m_str[1000 - m_len + i]) return true;
			if (m_str[1000 - m_len + i] > other.m_str[1000 - m_len + i]) return false;
		}
		return false; //����� ����������
	}

	//���� ��� ����� �������������
	if (m_len < other.m_len) return false;		//-123 < -5000 - false
	if (m_len > other.m_len) return true;		//-5000 < -123 - true

	for (int i = 0; i < m_len - 1; i++)				//-5001 < -5000
	{
		if (m_str[1000 - m_len + i] < other.m_str[1000 - m_len + i]) return false;
		if (m_str[1000 - m_len + i] > other.m_str[1000 - m_len + i]) return true;
	}

	return false; //����� ����������
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
	else //���� ��� ����� �������������
	{
		if (m_len > other.m_len) return true;		//5000 > 123 - true
		if (m_len < other.m_len) return false;		//123 > 5000 - false

		for (int i = 0; i < m_len; i++)				//5001 > 5000
		{
			if (m_str[1000 - m_len + i] > other.m_str[1000 - m_len + i]) return true;
			if (m_str[1000 - m_len + i] < other.m_str[1000 - m_len + i]) return false;
		}
		return false; //����� ����������
	}

	//���� ��� ����� �������������
	if (m_len > other.m_len) return false;		//-5000 > -123 - false
	if (m_len < other.m_len) return true;		//-123 > -5000 - true

	for (int i = 0; i < m_len - 1; i++)				//-5000 > -5001
	{
		if (m_str[1000 - m_len + i] > other.m_str[1000 - m_len + i]) return false;
		if (m_str[1000 - m_len + i] < other.m_str[1000 - m_len + i]) return true;
	}

	return false; //����� ����������
}

bool BigInt::operator==(const BigInt& other)
{
	if (m_len != other.m_len) return false;

	for (int i = 0; i < m_len; i++)				//-5001 == -5001 || 5001 == 5001
	{
		if (m_str[1000 - m_len + i] != other.m_str[1000 - m_len + i]) return false;
	}

	return true; //����� ����������
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

//��������� -1 ���� ����� �������������
//��������� 1 ���� ����� �������������
char BigInt::GetSign() const
{
	return m_str[999 - m_len] == '-' ? -1 : 1;
}




