#include <iostream>
/*
Ввести последовательность натуральных чисел {Aj}j=1...n (n<=1000). 
Упорядочить последовательность по неубыванию суммы цифр числа, 
числа с одинаковыми суммами цифр дополнительно упорядочить по неубыванию наименьшей цифры числа, 
числа с одинаковыми суммами цифр и одинаковыми наименьшими цифрами дополнительно упорядочить по неубыванию самого числа.
*/
int SumDigits(int num, int* minDigit)
{
    int result = 0;
    while (num)
    {
        int digit = num % 10;
        if (*minDigit > digit) *minDigit = digit;
        result += digit;
        num /= 10;
    }
    return result;
}

int main()
{
    const int N = 200;
    int mas[N];

    for (int i = 0; i < N; i++) mas[i] = i + 1;   //Fill massive

    for (int i = 0; i < N - 1; i++)
    {
        int s1 = 0, m1 = 9;
        s1 = SumDigits(mas[i], &m1);

        for (int o = i + 1; o < N; o++)
        {
            int s2 = 0, m2 = 9;
            s2 = SumDigits(mas[o], &m2);

            if (s1 > s2)
            {
                std::swap(mas[i], mas[o]);
                s1 = s2;
                m1 = m2;
                continue;
            }

            if (s1 == s2)
            {
                if (m1 > m2)
                {
                    std::swap(mas[i], mas[o]);
                    s1 = s2;
                    m1 = m2;
                    continue;
                }
                if (m1 == m2)
                {
                    if (mas[i] > mas[o])
                    {
                        std::swap(mas[i], mas[o]);
                        s1 = s2;
                        m1 = m2;
                    }
                        
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        std::cout << mas[i] << " ";
    }

    return 0;
}


