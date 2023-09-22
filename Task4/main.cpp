#include <iostream>

int main()
{
    int n;
    int mul = 1;
    std::cin >> n;

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


