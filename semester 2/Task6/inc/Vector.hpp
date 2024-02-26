#pragma once

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
			delete[] m_data;
			m_capacity = (size + 1) / 8;
			m_len = size;
			m_data = new char[(size + 1) / 8];
		}
	public:
		Vector(size_t size)
		{
			m_capacity = (size + 1) / 8;
			m_len = size;
			m_data = new char[(size + 1) / 8];
		}
		Vector& operator=(Vector& other) = delete;
		~Vector()
		{
			delete[] m_data;
		}
		void push_back(bool value)
		{
			set(m_len, value);
			++m_len;
		}
		bool operator[](int index)
		{
			return (m_data[index/8] & (1 << (7 - index%8)));
		}
		void set(size_t index, bool value)
		{
			if (index >= m_capacity)
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
		void insert();
		void erase();
	};
}