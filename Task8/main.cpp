/*
Ввести последовательность натуральных чисел. 
Если в последовательности нет простых чисел, то упорядочить последовательность по возрастанию суммы цифр. 
В противном случае удалить из последовательности числа, начинающиеся цифрой 7 
и продублировать числа, начинающиеся цифрой 3. 
Последовательность хранить в односвязном списке.
*/

#include <fstream>
#include <iostream>
#include <Functions.h>
#include <ListFunctions.h>


int main()
{
	std::ifstream in("input.txt");
	if (!in.is_open())
	{
		std::cout << "File not opened";
		return 0;
	}

	Node* root = new Node;
	Node* current = root;

	bool isHavePrime = false;

	while (!in.eof())
	{
		Node* temp = new Node;
		in >> temp->data;
		temp->next = nullptr;
		

		current->next = temp;
		current = temp;

		if (func::IsPrime(temp->data)) isHavePrime = true;
	}

	
	list::PrintList(root);

	if (!isHavePrime)
	{
		Node* first = root;
		Node* second = first->next;

		while (first->next != nullptr)
		{
			int sum_First = func::SumOfDigits(first->next->data);
			while (second != nullptr && second->next != nullptr)
			{
				int sum_Second = func::SumOfDigits(second->next->data);

				if (sum_First > sum_Second)
				{
					list::SwapNextNodes(first, second);
					sum_First = sum_Second;
				}
				second = second->next;
			}
			first = first->next;
			second = first->next;
		}

		list::PrintList(root);

		return 0;
	}

	return 0;
}