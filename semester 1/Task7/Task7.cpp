/*
Дана целочисленная матрица {Aij}i=1...n;j=1..n , n<=100. 
Если суммы цифр минимального и максимального элементов матрицы отличаются не более, чем на 2, 
упорядочить столбцы матрицы по возрастанию суммы элементов.
*/


#include "IntFunctions.hpp"
#include "FileFunctions.hpp"
#include "MatrixFunctions.hpp"
#include "MassiveFunctions.hpp"
#include "StringFunctions.hpp"

int main()
{
	char fileName[20] = "inputM.txt";
	char fileOut[20] = "outputM.txt";

	Matrix* mat = file::ReadSquareMatrix(fileName);
	int min = 9999999;
	int max = -9999999;

	int* sumElementsColumn = new int[mat->column];

	for (int i = 0; i < mat->column; i++)
	{
		int* column = matrix::ReadColumn(mat, i);
		sumElementsColumn[i] = massive::SumOfElementsSingle(column, mat->row);

		for (int o = 0; o < mat->row; o++)
		{
			min = intFunc::Min(min, column[o]);
			max = intFunc::Max(max, column[o]);
		}
	}
	
	if (intFunc::Abs(intFunc::SumOfDigit(max) - intFunc::SumOfDigit(min)) <= 2)
	{
		for (int i = 0; i < mat->column-1; i++)
		{
			int* column1 = matrix::ReadColumn(mat, i);
			int sum1 = massive::SumOfElementsSingle(column1, mat->row);

			for (int o = i + 1; o < mat->column; o++)
			{
				int* column2 = matrix::ReadColumn(mat, o);
				int sum2 = massive::SumOfElementsSingle(column2, mat->row);

				if (sum1 > sum2)
				{
					matrix::SwapColumn(mat, i, o);
					sum1 = sum2;
					column1 = column2;
					
				}
			}
		}
	}

	file::WriteMatrix(fileOut, mat);

	return 0;
}