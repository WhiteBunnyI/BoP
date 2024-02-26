#include <Matrix.hpp>
int main()
{
	my::Matrix<int, 3, 2> mat;
	my::Matrix<int, 2, 3> mat1;

	std::cin >> mat;
	std::cin >> mat1;

	std::cout << mat << std::endl;
	std::cout << mat1 << std::endl;

	auto mat2 = mat * mat1;
	std::cout << mat2 << std::endl;

	auto mat3 = mat2;

	mat3 *= 2;
	std::cout << mat3 << std::endl;

	++mat2;
	std::cout << mat2 << std::endl;

	std::cout << mat2.Determinant() << std::endl;

	mat(0, 0) = 12;
	std::cout << mat << std::endl;

}