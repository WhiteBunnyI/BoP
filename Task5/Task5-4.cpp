#include <iostream>
/*
Сначала введите последовательность. 
Затем удалите и продублируйте элементы. 
Затем выведите полученную последовательность (каждый элемент по одному разу). 
Используйте в программе только один массив.
*/

int main()
{
    const int N = 5;
    int mas[N];

    for (int i = 0; i < N; i++) std::cin >> mas[i];

    for (int i = 0; i < N; i++)
    {
        int temp = mas[i];
        mas[i] = 0;
        mas[i] = temp;
    }

    for (int i = 0; i < N; i++)
    {
        bool found = false;
        if (i == 0)
        {
            std::cout << mas[i] << " ";
            continue;
        }
        for (int o = 0; o < i; o++)
        {
            if (mas[i] == mas[o])
            {
                found = true;
                break;
            }
        }
        if(!found) std::cout << mas[i] << " ";
        
    }
    return 0;
}


