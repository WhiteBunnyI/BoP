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
    int digits[10]{ 0,0,0,0,0,0,0,0,0,0 };
    while (num)
    {
        int d = num % 10;
        if (digits[d]) return true;
        digits[d] = 1;
        num /= 10;
    }
    return false;
}

int main()
{
    const int N = 100;
    int mas[N*2];

    for (int i = 0; i < N; i++)
    {
        mas[i] = i + 1;
    }

    int leftEmpty = -1;
    int rightEmpty = N;
    for (int i = 0; i < N; i++)
    {
        if (SumDigits(mas[i]) % 7 == 0) //Если сумма цифр числа кратна 7, удаляем число
        {
            mas[i] = 0;
            if (leftEmpty == -1 || leftEmpty > i) leftEmpty = i; //Ставим левый указатель, если он пустой, на удаленную ячейку
            continue;
        }
        if (IsHavePair(mas[i]))
        {
            if (leftEmpty != -1) //Если указатель слева указывает на "пустую" ячейку, то
            {
                mas[leftEmpty] = mas[i]; //Дублируем число в эту ячейку

                bool found = false;
                for (int o = leftEmpty; o < i; o++) //Проходим от левого указателя до текущего положения
                {
                    if (mas[o] == 0) //Если есть "пустая" ячейка, то ставим указатель на него
                    {
                        found = true;
                        leftEmpty = o;
                        break;
                    }
                }

                if(!found) leftEmpty = -1; //Если же "пустой" ячейки не нашлось, то указатель не будет ни на что указывать)
                
            }
            else                //Иначе дублируем число в правый указатель
            {
                mas[rightEmpty] = mas[i];
                rightEmpty++;
            }
            
        }

    }

    for (int i = 0; i < std::size(mas); i++) std::cout << mas[i] << " "; //Выводим массив

    return 0;
}


