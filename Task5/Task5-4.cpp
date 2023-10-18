﻿#include <iostream>
/*
Сначала введите последовательность.
Затем удалите и продублируйте элементы.
Затем выведите полученную последовательность (каждый элемент по одному разу).
Используйте в программе только один массив.
*/

int main()
{
    const int N = 5;
    int mas[N*2];

    for (int i = 0; i < N; i++) std::cin >> mas[i];			//Заполняем массив

    for (int i = 0; i < N; i++) 							//Дублируем и удаляем элементы
    {
        mas[N + i] = mas[i];
        mas[i] = 0;
    }

    for (int i = 0; i < N; i++) std::cout << mas[i] << " ";	//Выводим массив
    std::cout << "\n";

    for (int i = 0; i < N; i++) 							//Возвращаем элементы 
    {
        mas[i] = mas[N + i];
    }

    for (int i = 0; i < N; i++) std::cout << mas[i] << " ";	//Выводим массив
    std::cout << "\n";

    return 0;
}
