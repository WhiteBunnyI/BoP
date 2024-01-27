#include <Ellipse.hpp>
#define _USE_MATH_DEFINES
#include <cmath>


Ellipse::Ellipse(int x, int y, int a, int b)
{
	m_x = x;
	m_y = y;
	m_a = a;
	m_b = b;
}

Ellipse::~Ellipse() {}

void Ellipse::SetCoords(int x, int y)
{
	m_x = x;
	m_y = y;
}

void Ellipse::SetLenSemiAxes(int a, int b)
{
	m_a = a;
	m_b = b;
}

float Ellipse::GetSquare()
{
	return M_PI * m_a * m_b;
}

float Ellipse::GetPerimeter()
{
	return 2 * M_PI * std::sqrt((m_a * m_a + m_b * m_b)/2);
}

int Ellipse::GetCoord_X()
{
	return m_x;
}

int Ellipse::GetCoord_Y()
{
	return m_y;
}

int Ellipse::GetLenSemiAxe_A()
{
	return m_a;
}

int Ellipse::GetLenSemiAxe_B()
{
	return m_b;
}
