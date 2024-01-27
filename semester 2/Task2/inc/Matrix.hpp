#pragma once

class Matrix
{
	int m_row;
	int m_column;
	int** m_matrix;

public:
	Matrix(int row, int column);
	Matrix(const Matrix& other);
	Matrix& operator =(Matrix other);
	Matrix& operator +(const Matrix& other);
	Matrix& operator -(const Matrix& other);
	~Matrix();
	int GetCountRow();
	int GetCountColumn();
	int GetValue(int row, int column) const;
	void SetValue(int row, int column, int value);
	void Print();
private:
	void Swap(Matrix& other);
};