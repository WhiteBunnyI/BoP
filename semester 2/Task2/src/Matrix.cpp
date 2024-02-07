#include "Matrix.hpp"
#include <iostream>

Matrix::Matrix(int row, int column)
{
	m_row = row;
	m_column = column;
	m_matrix = new int* [row];
	for (int i = 0; i < row; i++)
	{
		m_matrix[i] = new int[column];
	}
}

Matrix::Matrix(const Matrix& other) : Matrix::Matrix(other.m_row, other.m_column)
{
	for (int row = 0; row < m_row; row++)
	{
		for (int col = 0; col < m_column; col++)
		{
			m_matrix[row][col] = other.GetValue(row, col);
		}
	}
}

Matrix& Matrix::operator =(Matrix other)
{
	Swap(other);
	return *this;
}

Matrix& Matrix::operator +(const Matrix& other)
{
	if (m_row != other.m_row || m_column != other.m_column) 
		return *this;

	for (int i = 0; i < m_row; i++)
	{
		for (int o = 0; o < m_column; o++)
		{
			m_matrix[i][o] += other.GetValue(i, o);
		}
	}

	return *this;
}

Matrix& Matrix::operator +=(const Matrix& other)
{
	if (m_row != other.m_row || m_column != other.m_column)
		return *this;

	for (int i = 0; i < m_row; i++)
	{
		for (int o = 0; o < m_column; o++)
		{
			m_matrix[i][o] += other.GetValue(i, o);
		}
	}

	return *this;
}

Matrix& Matrix::operator -=(const Matrix& other)
{
	if (m_row != other.m_row || m_column != other.m_column)
		return *this;

	for (int i = 0; i < m_row; i++)
	{
		for (int o = 0; o < m_column; o++)
		{
			m_matrix[i][o] -= other.GetValue(i, o);
		}
	}

	return *this;
}

Matrix& Matrix::operator -(const Matrix& other)
{
	if (m_row != other.m_row || m_column != other.m_column)
		return *this;

	for (int i = 0; i < m_row; i++)
	{
		for (int o = 0; o < m_column; o++)
		{
			m_matrix[i][o] -= other.GetValue(i, o);
		}
	}

	return *this;
}

Matrix::~Matrix()
{
	for (int i = 0; i < m_row; i++)
		delete[] m_matrix[i];
	delete[] m_matrix;
}

int Matrix::GetCountRow()
{
	return m_row;
}

int Matrix::GetCountColumn()
{
	return m_column;
}

int Matrix::GetValue(int row, int column) const
{
	return m_matrix[row][column];
}

void Matrix::SetValue(int row, int column, int value)
{
	m_matrix[row][column] = value;
}

void Matrix::Swap(Matrix& other)
{
	std::swap(m_row, other.m_row);
	std::swap(m_column, other.m_column);
	std::swap(m_matrix, other.m_matrix);
}

void Matrix::Print()
{
	for (int i = 0; i < m_row; i++)
	{
		for (int o = 0; o < m_column; o++)
		{
			std::cout << GetValue(i, o) << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}