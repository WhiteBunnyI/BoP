#include <iostream>

int main()
{
    long long mul = 1;
    int greatest = 0;
    int index = 0;

    for (int A = 0; A < 20; A++) 
    {
        if (A % 5) 
        {
            mul *= A;

            if (greatest < A)
            {
                greatest = A;
                index = A;
            }

        }
    }

    std::cout << "Multiply: " << mul << " Greatest number: " << greatest << " Index of greatest number: " << index;

    return 0;
}


