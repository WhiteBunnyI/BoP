#include <cmath>
#include <iostream>
#include <Ellipse.hpp>

/*
Создайте класс, описывающий указанный в вашем варианте реальный объект. Не забывайте про принципы абстракции и инкапсуляции.
В классе необходимо реализовать конструктор и деструктор (даже если они дефолтные). Класс разбейте на hpp и cpp файлы. Продемонстрируйте использование вашего класса.

8. Эллипс, расчет площади, периметра.
*/

int main()
{
	Ellipse ell1(5, 8, 9, 4);

	std::cout << "X: " << ell1.GetCoord_X() << std::endl;
	std::cout << "Y: " << ell1.GetCoord_Y() << std::endl;
	std::cout << "Semi axe A: " << ell1.GetLenSemiAxe_A() << std::endl;
	std::cout << "Semi axe B: " << ell1.GetLenSemiAxe_B() << std::endl;
	std::cout << "Square: " << ell1.GetSquare() << std::endl;
	std::cout << "Perimeter " << ell1.GetPerimeter() << std::endl << std::endl;

	ell1.SetLenSemiAxes(2, 5);

	std::cout << "X: " << ell1.GetCoord_X() << std::endl;
	std::cout << "Y: " << ell1.GetCoord_Y() << std::endl;
	std::cout << "Semi axe A: " << ell1.GetLenSemiAxe_A() << std::endl;
	std::cout << "Semi axe B: " << ell1.GetLenSemiAxe_B() << std::endl;
	std::cout << "Square: " << ell1.GetSquare() << std::endl;
	std::cout << "Perimeter " << ell1.GetPerimeter() << std::endl << std::endl;

	ell1.SetCoords(1, 1);

	std::cout << "X: " << ell1.GetCoord_X() << std::endl;
	std::cout << "Y: " << ell1.GetCoord_Y() << std::endl;
	std::cout << "Semi axe A: " << ell1.GetLenSemiAxe_A() << std::endl;
	std::cout << "Semi axe B: " << ell1.GetLenSemiAxe_B() << std::endl;
	std::cout << "Square: " << ell1.GetSquare() << std::endl;
	std::cout << "Perimeter " << ell1.GetPerimeter() << std::endl << std::endl;

	return 0;
}