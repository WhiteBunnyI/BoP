#include <iostream>

int Task3()
{
    setlocale(LC_ALL, "rus");

    int a, b, c;

    std::cout << "¬ведите числа A, B, C: \n";
    std::cin >> a >> b >> c;

    if (!(a % c) && !(b % c)) std::cout << ((a + b) / c);
    else if (!(a % c)) std::cout << (a / c + b);
    else std::cout << (a - b - c);

    return 0;
}