#include <iostream>
/*
Дана последовательность натуральных чисел {aj}j=1...n (n<=10000).
Если в последовательности есть не менее 3-х чисел,
все цифры которых одинаковы, упорядочить последовательность по невозрастанию.
*/


int main()
{
    const int N = 10;
    int mas[N];

    for (int i = 0; i < N; i++) std::cin >> mas[i];   //Fill massive
    std::cout << std::endl;

    int count = 0;
    for (int i = 0; i < N; i++)                       //Check
    {
        int num = mas[i];

        if (num < 10) continue;

        int digit = num % 10;
        num /= 10;
        count++;

        while (num)
        {
            int othDigit = num % 10;
            num /= 10;
            if (othDigit != digit)
            {
                count--;
                break;
            }
        }

    }

    if (count >= 3)
    {
        for (int i = 0; i < N - 1; i++)             //Sort
        {
            for (int o = i + 1; o < N; o++)
            {
                if (mas[i] < mas[o])
                {
                    std::swap(mas[i], mas[o]);
                }
            }
        }
    }

    for (int i = 0; i < N; i++) std::cout << mas[i] << " "; //Output

    return 0;
}


