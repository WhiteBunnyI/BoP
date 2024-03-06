#pragma once
#include <iostream>
namespace my
{
	template<typename T>
	class Vector{};

	template<>
	class Vector<bool>
	{
		char* m_data;
		size_t m_len;
		size_t m_capacity;

		void resize(size_t size)
		{
			m_capacity = (size + 1) / 8 + 1;
			char* temp = new char[m_capacity];
			std::copy(m_data, m_data + m_capacity - 1, temp);
			std::swap(temp, m_data);
			delete[] temp;
		}

	public:
		Vector(size_t size)
		{
			m_capacity = (size + 1) / 8 + 1;
			m_len = 0;
			m_data = new char[m_capacity];
		}

		Vector& operator=(Vector& other) = delete;

		~Vector()
		{
			delete[] m_data;
		}

		void push_back(bool value)
		{
			if (m_len + 1 >= m_capacity * 8)
				resize(m_len + 1);
			set(m_len, value);
			++m_len;
		}

		bool operator[](size_t index)
		{
			return (m_data[index/8] & (1 << (7 - index%8)));
		}

		void set(size_t index, bool value)
		{
			if (index >= m_capacity * 8)
				resize(index);
			if (value)
				m_data[index / 8] = m_data[index / 8] | (1 << (7 - index % 8));
			else
				m_data[index / 8] = m_data[index / 8] & ~(1 << (7 - index % 8));
		}

		size_t size()
		{
			return m_len;
		}

		void insert(size_t index, bool value)
		{														
			if (m_len + 1 >= m_capacity * 8)					
				resize(m_len + 1);								
			for (int i = m_len + 1; i > index; i--)				
			{													
				set(i, (*this)[i - 1]);
			}
			set(index, value);
			++m_len;
		}

		void erase(size_t index)
		{
			for (int i = index; i < m_len; i++)
			{
				set(i, (*this)[i + 1]);
			}
			--m_len;
		}
	};
}