#include <iostream>


int main()
{
    const int N = 60;
    int mas[N];

    for (int i = 0; i < N; i++) mas[i] = i+1;   //Fill massive

    if (N < 33) return 0;                       //Check

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

    for (int i = 0; i < N; i++) std::cout << mas[i] << " ";

    return 0;
}


