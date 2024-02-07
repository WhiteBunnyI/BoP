#include <cmath>
#include <iostream>
#include <Matrix.hpp>
/*
Создайте класс, описывающий матрицу размерами NxM. Не забывайте про принципы абстракции и инкапсуляции.
В классе реализуйте конструктор копирования, оператор присваивания копированием и деструктор. Продемонстрируйте использование вашего класса.
*/

int main()
{
	Matrix mat(3, 4);

	for (int i = 0; i < mat.GetCountRow(); i++)
	{
		for (int o = 0; o < mat.GetCountColumn(); o++)
		{
			int value;
			std::cout << "Set value for row: " << i << " and column: " << o << " Value: ";
			std::cin >> value;

			mat.SetValue(i, o, value);

		}
	}
	mat.Print();
	Matrix mat1 = mat;
	mat1.SetValue(0, 0, -1);
	mat.Print();
	mat1.Print();

	mat = mat1;
	mat1.SetValue(0, 0, 100);
	mat.Print();
	mat1.Print();

	mat += mat1;
	mat.Print();
	mat1.Print();

	mat1 -= mat;
	mat.Print();
	mat1.Print();

	return 0;
}