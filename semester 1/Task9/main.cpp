/*
Ввести последовательность натуральных чисел. 
Если в последовательности нет трехзначных чисел, состоящих только из нечетных цифр, 
упорядочить последовательность по убыванию первой цифры. 
В противном случае удалить из последовательности числа не содержащие цифру 8, и продублировать остальные числа. 
Последовательность хранить в двусвязном циклическом списке с фиктивным элементом.
*/

#include <ListFunctions.h>
#include <Functions.h>
#include <iostream>
#include <fstream>

int main()
{
	std::ifstream in("Input.txt");

	if (!in.is_open())
	{
		std::cout << "File not opened" << '\n';

		return 0;
	}

	Node* root = new Node;

	Node* current = root;
	bool isHaveThreeWithOddDigits = false;
	while (!in.eof())
	{
		Node* newNode = new Node;
		in >> newNode->data;
		newNode->prev = current;
		current->next = newNode;
		newNode->next = root->next;
		root->next->prev = newNode;

		current = newNode;

		if (isHaveThreeWithOddDigits) continue;

		int temp = (newNode->data / 100);
		if (temp > 0 && temp < 10)
		{
			isHaveThreeWithOddDigits = !func::IsHaveEvenDigit(newNode->data);
		}

	}
	list::PrintForward(root);

	/*list::PrintForward(root);
	list::PrintBack(root);
	list::SwapNode(root, root->next, root->next->next);
	list::PrintForward(root);
	list::PrintBack(root);
	return 0; */

	if (!isHaveThreeWithOddDigits)
	{
		Node* first = root->next;
		Node* second = first->next;

		do
		{
			while (root->next != second)
			{
				int digit_First = func::GetFirstDigit(first->data);
				int digit_Second = func::GetFirstDigit(second->data);

				if (digit_First < digit_Second)
				{
					list::SwapNode(root, first, second);
					std::swap(first, second);
				}
				second = second->next;
			}
			first = first->next;
			second = first->next;

		} while (root->next != first);



		list::PrintForward(root);
		return 0;
	}

	current = root->next;
	do
	{
		if (!func::isHaveDigitInNum(current->data, 8))
		{
			current = current->next;
			list::DeleteNode(root, current->prev);
			continue;
		}
		else
		{
			list::DuplicateNode(current);
			current = current->next;
		}
		
		current = current->next;
	} while (root->next != current);

	if (!func::isHaveDigitInNum(current->data, 8))
	{
		current = current->next;
		list::DeleteNode(root, current->prev);
	}
	else
	{
		list::DuplicateNode(current);
		current = current->next;
	}

	list::PrintForward(root);
	return 0;
}