#pragma once
#include <iostream>
namespace my
{
	template<typename T, int N, int M>
	class Matrix
	{
		T m_matrix[N][M];

		void copy(const Matrix& other)
		{
			for (int i = 0; i < N; i++)
			{
				for (int o = 0; o < M; o++)
				{
					m_matrix[i][o] = other.m_matrix[i][o];
				}
			}
		}

	public:
		Matrix() = default;
		Matrix(const Matrix& other)
		{
			copy(other);
		}
		Matrix& operator=(const Matrix& other)
		{
			copy(other)
			return *this;
		}

		friend std::istream& operator>>(std::istream& is, Matrix<T, N, M>& obj)
		{
			char str[10000];
			is.getline(str, 10000);
			int size = strlen(str);
			int num = 0;
			int count = 0;
			for (int i = 0; i < size || num; i++)
			{
				if (count / M == N) break;
				if (str[i] == ' ' || str[i] == '\0')
				{
					obj.m_matrix[count / M][count % M] = num;
					++count;
					num = 0;
					continue;
				}
				if (str[i] < '0' && str[i] > '9')
				{
					std::cerr << "Wrong char " << str[i] << std::endl;
					break;
				}
				num *= 10;
				num += str[i] - 48;
			}

			return is;
		}

		friend std::ostream& operator<<(std::ostream& os, Matrix<T, N, M>& obj)
		{
			for (int i = 0; i < N; i++)
			{
				for (int o = 0; o < M; o++)
				{
					os << obj.m_matrix[i][o] << ' ';
				}
				os << std::endl;
			}
			return os;
		}

		Matrix& operator+=(Matrix& other)
		{
			for (int i = 0; i < N; i++)
			{
				for (int o = 0; o < M; o++)
				{
					m_matrix[i][o] += other(i, o);
				}
			}
			return *this;
		}

		Matrix& operator+(Matrix& other)
		{
			Matrix temp(*this);
			temp += other;
			return temp;
		}

		Matrix& operator*=(T other)
		{
			for (int i = 0; i < N; i++)
			{
				for (int o = 0; o < M; o++)
				{
					m_matrix[i][o] *= other;
				}
			}
			return *this;
		}

		template<int H>
		Matrix<T, N, H> operator*(Matrix<T, M, H>& other)
		{
			Matrix<T, N, H> result;
			int count = 0;
			for (int i = 0; i < H; i++)
			{
				for (int o = 0; o < N; o++)
				{
					T temp{};
					for (int p = 0; p < M; p++)
					{
						temp += m_matrix[o][p] * other(p, i);
					}
					result(o, i) = temp;
				}
			}
			return result;
		}

		Matrix& operator*(Matrix& other)
		{
			Matrix temp(*this);
			temp *= other;
			return temp;
		}

		Matrix& operator++()
		{
			for (int i = 0; i < N; i++)
			{
				for (int o = 0; o < M; o++)
				{
					++m_matrix[i][o];
				}
			}
			return *this;
		}

		T& operator()(int row, int column)
		{
			return m_matrix[row][column];
		}

		int Determinant()
		{
			if (N != M || N > 3 || M > 3)
			{
				std::cerr << "Wrong matrix" << std::endl;
				return 0;
			}
			if (N == 1) return m_matrix[0][0];
			if (N == 2)
			{
				return (m_matrix[0][0] * m_matrix[1][1] - m_matrix[0][1] * m_matrix[1][0]);

			}
			if (N == 3)
			{
				return m_matrix[0][0] * m_matrix[1][1] * m_matrix[2][2] +
					m_matrix[0][1] * m_matrix[1][2] * m_matrix[2][0] +
					m_matrix[1][0] * m_matrix[2][1] * m_matrix[0][2] -
					m_matrix[0][2] * m_matrix[1][1] * m_matrix[2][0] -
					m_matrix[0][1] * m_matrix[1][0] * m_matrix[2][2] -
					m_matrix[0][0] * m_matrix[1][2] * m_matrix[2][1];
			}
			return 0;
		}

	};
}

