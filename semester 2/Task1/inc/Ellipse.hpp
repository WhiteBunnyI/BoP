#pragma once

class Ellipse
{
	int m_x;
	int m_y;
	int m_a;
	int m_b;

public:

	Ellipse(int x, int y, int a, int b);

	~Ellipse();

	void SetCoords(int x, int y);

	void SetLenSemiAxes(int a, int b);

	float GetSquare();

	float GetPerimeter();

	int GetCoord_X();

	int GetCoord_Y();

	int GetLenSemiAxe_A();

	int GetLenSemiAxe_B();
};