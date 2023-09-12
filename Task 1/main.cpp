//Вариант 1
#include <iostream>

float GetTriangleArea(float a, float b, float c) {
    float p = (a + b + c) / 2;                           //Полупериметр понадобится нам для вычисления площади по формуле Герона
    float area = sqrt(p * (p - a) * (p - b) * (p - c)); //Формула Герона (См. в википедии)
    return area;
}

int main()
{
    float a, b, c;
    std::cout << "Enter the sides of the triangle (Example: 4 3 2): \n";
    std::cin >> a >> b >> c;
    float result = GetTriangleArea(a, b, c);
    std::cout << result;
    return 0;
}


