#pragma once

class Matrix
{
	int m_row;
	int m_column;
	int** m_matrix;

public:
	Matrix(int row, int column);				//Конструктор
	Matrix(const Matrix& other);				//Конструктор копирования
	Matrix& operator =(Matrix other);			//Оператор присваивания копированием
	Matrix& operator +(const Matrix& other);	//фича
	Matrix& operator +=(const Matrix& other);	//фича
	Matrix& operator -=(const Matrix& other);	//фича
	Matrix& operator -(const Matrix& other);	//фича
	~Matrix();
	int GetCountRow();
	int GetCountColumn();
	int GetValue(int row, int column) const;
	void SetValue(int row, int column, int value);
	void Print();
private:
	void Swap(Matrix& other);
};