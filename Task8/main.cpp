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
		list::SortList(root);
		list::PrintList(root);

		return 0;
	}
	current = root;

	while (current->next != nullptr)
	{
		int firstDigit = func::GetFirstDigit(current->next->data);
		if (firstDigit == 7)
		{
			list::DeleteNextNode(current);
			continue;
		}
		if (firstDigit == 3)
		{
			list::DuplicateNextNode(current);
			current = current->next;
		}
		current = current->next;
	}

	list::PrintList(root);

	return 0;
}