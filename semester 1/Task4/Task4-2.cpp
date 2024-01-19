#include <iostream>
/*
Дано натуральное число N (N<10^9). 
Найти произведение нечетных цифр числа N.
*/
int main()
{
    int n = 535135;
    int mul = 1;

    while (n)
    {
        int rest = n % 10;
        n = n / 10;
        if (rest % 2)
        {
            mul *= rest;
        }
    }
    std::cout << mul;
    return 0;
}


