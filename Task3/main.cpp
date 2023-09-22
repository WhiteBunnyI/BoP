#include <iostream>

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


