#include <iostream>
/*
Ввести последовательность натуральных чисел {Aj}j=1...n (n<=1000).
Упорядочить последовательность по возрастанию суммы цифр числа,
числа с одинаковыми суммами цифр дополнительно упорядочить по возрастанию наименьшей цифры числа,
числа с одинаковыми суммами цифр и одинаковыми наименьшими цифрами дополнительно упорядочить по возрастанию самого числа.
*/
int SumDigits(int num, int& minDigit)
{
    int result = 0;
    while (num)
    {
        int digit = num % 10;
        if (minDigit > digit) minDigit = digit;
        result += digit;
        num /= 10;
    }
    return result;
}

int main()
{ 
    const int N = 4;
    int mas[N];

    for (int i = 0; i < N; i++) std::cin >> mas[i];   //Заполняем массив

    for (int i = 0; i < N - 1; i++)
    {
        int s1 = 0, m1 = 9;
        s1 = SumDigits(mas[i], m1);

        for (int o = i + 1; o < N; o++)
        {
            int s2 = 0, m2 = 9;
            s2 = SumDigits(mas[o], m2);

            if (s1 > s2)                            //Если сумма цифр первого числа больше второго - меняем местами числа
            {
                std::swap(mas[i], mas[o]);
                s1 = s2;
                m1 = m2;
                continue;
            }

            if (s1 == s2)                           //Если сумма цифр одинаковы то
            {
                if (m1 > m2)                        //В случае если наименьшая цифра первого числа больше второго числа - меняем числа
                {
                    std::swap(mas[i], mas[o]);
                    s1 = s2;
                    m1 = m2;
                    continue;
                }
                if (m1 == m2)                       //Если наименьшие числа одинаковы то
                {
                    if (mas[i] > mas[o])            //В случае если первое число больше - меняем числа
                    {
                        std::swap(mas[i], mas[o]);
                        s1 = s2;
                        m1 = m2;
                    }

                }
            }
        }
    }

    for (int i = 0; i < N; i++)                     //Вывод массива
    {
        std::cout << mas[i] << " ";
    }

    return 0;
}


