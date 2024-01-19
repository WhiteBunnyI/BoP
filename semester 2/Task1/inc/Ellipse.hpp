#pragma once

class Ellipse
{
	float m_x;
	float m_y;
	float m_a;
	float m_b;

public:
	Ellipse() = default;

	Ellipse(float x, float y, float a, float b);

	~Ellipse();

	void SetCoords(float x, float y);

	void SetLenSemiAxes(float a, float b);

	float GetSquare();

	float GetPerimeter();


};