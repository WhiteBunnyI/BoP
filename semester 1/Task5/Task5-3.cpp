#include <iostream>
/*
Дана целочисленная матрица {Aij}i=1..n,j=1..m (n,m<=100).
Найти столбец с наибольшим произведением элементов и
уменьшить все элементы этого столбца на 3.
*/
void printMassive(int* mas, int N, int J)
{
    for (int n = 0; n < N; n++)
    {
        for (int j = 0; j < J; j++)
        {
            std::cout << *(mas + j + n * N) << " ";
        }
        std::cout << '\n';
    }
}

int main()
{
    const int N = 4;
    const int J = 4;
    int mas[N][J];


    for (int n = 0; n < N; n++)				//Заполняем массив
    {
        for (int j = 0; j < J; j++)
        {
            std::cin >> mas[n][j];
        }
    }
    
    long long maxMul = 0; int maxN = 0;		//Находим максимальное произведение и его индекс
    for (int j = 0; j < J; j++)
    {
        long long mul = 1;
        for (int n = 0; n < N; n++)
        {
            mul *= mas[n][j];
        }

        if (maxMul < mul)
        {
            maxMul = mul;
            maxN = j;
        }
    }
    for (int j = 0; j < J; j++)				//Делим значения столбца на 3
    {
        mas[j][maxN] /= 3;
    }

    std::cout << "\n";
    printMassive(mas[0], N, J);

    return 0;
}


