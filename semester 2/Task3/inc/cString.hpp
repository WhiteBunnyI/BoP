#pragma once
#include <iostream>

namespace my
{
	class String
	{
		char* m_str;
		size_t m_len;
		size_t m_capacity;

	public:
		String(char* str);
		String(const String& other);
		String& operator=(String& other);
		~String();

		String& operator+=(const String& other);
		String& operator+=(const char* other);
		String& operator+=(const char other);

		String operator+(const String& other);
		String operator+(const char* other);
		String operator+(const char other);

		char& operator[](std::size_t idx);

		bool operator<(String& other);
		bool operator>(String& other);
		bool operator==(String& other);

	 	friend std::ostream& operator<<(std::ostream& os, String& obj);
		friend std::istream& operator>>(std::istream& is, String& obj);

		int Find(char chr);
		int Length();
		char* C_str();
		char& At(size_t idx);
		void RecalculateCapacity();
	};

}