#include <cString.hpp>

namespace my
{
	String::String(int len)
	{
		m_len = 0;
		m_capacity = len;
		m_str = new char[m_capacity];
	}
	String::String(char* str)
	{
		m_len = strlen(str) + 1;
		m_capacity = m_len * 2;
		m_str = new char[m_capacity];
		std::copy(str, str + m_len, m_str);
	}

	String::String(const String& other)
	{
		m_len = other.m_len;
		m_capacity = other.m_capacity;
		m_str = new char[m_capacity];
		std::copy(other.m_str, other.m_str + m_len, m_str);
	}

	String& String::operator=(String& other)
	{
		delete[] m_str;
		m_len = other.m_len;
		m_str = new char[m_len];
		std::copy(other.m_str, other.m_str + m_len, m_str);
		return *this;
	}

	String::~String()
	{
		delete[] m_str;
	}

	String& String::operator+=(const String& other)
	{
		String temp(m_len + other.m_len - 1);
		std::copy(m_str, m_str + m_len - 1, temp.m_str);
		std::copy(other.m_str, other.m_str + other.m_len, temp.m_str - 1 + m_len);
		std::swap(*this, temp);
		return *this;
	}
	String& String::operator+=(const char* other)
	{
		size_t len = strlen(other);
		if (m_capacity < m_len + len)
		{
			String temp(len * 2);
			std::swap(*this, temp);
			std::copy(m_str, m_str + m_len - 1, m_str);					//Передаелать чтоб копировалось сразу в наш объект после замены
			std::copy(other, other + len + 1, m_str - 1 + m_len);			
			return *this;
		}

		std::copy(other, other + len + 1, m_str + m_len - 1);
		
		return *this;
	}
	String& String::operator+=(const char other)
	{
		if (m_capacity < m_len + 1)
		{
			String temp(m_capacity*2);
			std::copy(m_str, m_str + m_len - 1, temp.m_str);
			std::copy(other, other + len + 1, temp.m_str - 1 + m_len);
			std::swap(*this, temp);
			return *this;
		}
		
		return *this;
	}


	String String::operator+(const String& other)
	{
		String temp(*this);
		temp += other;
		return temp;
	}
	String String::operator+(const char* other)
	{
		String temp(*this);
		temp += other;
		return temp;
	}


	char& String::operator[](size_t idx)
	{
		return m_str[idx];
	}

	bool String::operator<(String& other)
	{
		if (m_len < other.m_len) return true;
		return false;

		/*int i = 0;
		while (other[i] != '\0')
		{
			if (m_str[i] < other[i]) return true;
			if (m_str[i] > other[i]) return false;
			i++;
		}
		return false;*/
	}

	bool String::operator>(String& other)
	{
		if (m_len > other.m_len) return true;
		return false;
	}

	bool String::operator==(String& other)
	{
		if (m_len != other.m_len) return false;

		int i = 0;
		while (other[i] != '\0')
		{
			if (m_str[i] != other[i]) return false;
			i++;
		}
		return true;
	}

	std::ostream& operator<<(std::ostream& os, String& obj)
	{
		os << obj.m_str;
		return os;
	}

	std::istream& operator>>(std::istream& is, String& obj)
	{
		char str[10000];
		is.getline(str, 10000);
		String temp(str);
		std::swap(obj, temp);
		return is;
	}

	int String::Find(char chr)
	{
		for (int i = 0; i < m_len; i++)
		{
			if (m_str[i] == chr) return i;
		}
		return -1;
	}

	int String::Length()
	{
		return m_len;
	}

	char* String::C_str()
	{
		return m_str;
	}

	char& String::At(size_t idx)
	{
		if (idx > m_len) return m_str[0];
		return m_str[idx];
	}




}