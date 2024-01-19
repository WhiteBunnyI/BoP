#include <iostream>

/*
Дана последовательность натуральных чисел {Aj}j=1...n (n<=10000).
Удалить из последовательности числа,
сумма цифр которых кратна 7,
а среди оставшихся продублировать числа,
содержащие хотя бы пару одинаковых цифр.
*/

int SumDigits(int num)
{
    int res = 0;
    while (num)
    {
        res += num % 10;
        num /= 10;
    }
    return res;
}
bool IsHavePair(int num)
{
    bool digits[10]{ 0,0,0,0,0,0,0,0,0,0 };
    while (num)
    {
        int d = num % 10;
        if (digits[d]) return true;
        digits[d] = true;
        num /= 10;
    }
    return false;
}

int main()
{
    const int N = 10;
    int mas[N * 2];
    int len = N;

    for (int i = 0; i < N; i++) std::cin >> mas[i]; //Заполняем массив

    int rightEmpty = N;
    for (int i = 0; i < len; i++)
    {
        if (SumDigits(mas[i]) % 7 == 0)             //Если сумма цифр числа кратна 7, удаляем число
        {
            for (int o = i + 1; o < len; o++)
            {
                mas[o - 1] = mas[o];
            }
            len--;
            i--;
            continue;
        }
        if (IsHavePair(mas[i]))                     //Дублируем, если у числа есть пара одинаковых цифр
        {
            for (int o = len - 1; o >= i; o--)
            {
                mas[o + 1] = mas[o];

            }
            len++;
            i++;
        }
    }

    for (int i = 0; i < len; i++) std::cout << mas[i] << " "; //Выводим массив

    return 0;
}


