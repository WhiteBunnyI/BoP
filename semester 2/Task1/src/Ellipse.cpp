#include <Ellipse.hpp>
#define _USE_MATH_DEFINES
#include <cmath>


Ellipse::Ellipse(float x, float y, float a, float b)
{
	m_x = x;
	m_y = y;
	m_a = a;
	m_b = b;
}

Ellipse::~Ellipse() {}

void Ellipse::SetCoords(float x, float y)
{
	m_x = x;
	m_y = y;
}

void Ellipse::SetLenSemiAxes(float a, float b)
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
