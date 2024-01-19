#include <cmath>

int Task2(int x, int i)
{
    int mask = static_cast<int>(pow(2, i));
    return x - mask;
}
