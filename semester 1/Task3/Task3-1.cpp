#include <iostream>
/*
Ввести натуральные числа A, B и C. Если A кратно C и B кратно C, то вывести (A+B)/C, 
если A кратно C и B не кратно C, то вывести A/С+B, в остальных случаях вывести A-B-C.
*/
int Task3()
{
    setlocale(LC_ALL, "rus");

    int a, b, c;

    std::cout << "Введите числа A, B, C: \n";
    std::cin >> a >> b >> c;

    if (!(a % c) && !(b % c)) std::cout << ((a + b) / c);
    else if (!(a % c)) std::cout << (a / c + b);
    else std::cout << (a - b - c);

    return 0;
}
