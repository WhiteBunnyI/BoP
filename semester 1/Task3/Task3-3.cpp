#include <iostream>
/*
 Переменная x может принимать 2 значения: -1 и 1. 
 Если -1, то вывести в консоль “Negative number”, если положительное - “Positive number”. 
 Предложить вариант программы и объяснить свой выбор.
*/

int main()
{
    int x;
    std::cin >> x;

	if (x == 1) 
	{
		std::cout << "Positive number \n";
	}
	else if (x == -1) 
	{
		std::cout << "Negative number \n";
	}
	else 
	{
		std::cout << "Unknown number \n";
	}

    return 0;
}


