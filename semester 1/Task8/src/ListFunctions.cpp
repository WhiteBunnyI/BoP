#include <ListFunctions.h>

namespace list
{
	void SwapNextNodes(Node* first, Node* second)
	{
		std::swap(first->next, second->next);
		std::swap(first->next->next, second->next->next);
		
	}

	void PrintList(Node* root)
	{

		while (root->next != nullptr)
		{
			std::cout << root->next->data << " ";
			root = root->next;
		}
		std::cout << '\n';
	}

	void SortList(Node* root)
	{
		Node* firstRoot = root;
		Node* secondRoot = firstRoot->next;

		while (firstRoot->next != nullptr)
		{
			while (secondRoot != nullptr && secondRoot->next != nullptr)
			{
				Node* first = firstRoot->next;
				Node* second = secondRoot->next;

				int sum_First = func::SumOfDigits(first->data);
				int sum_Second = func::SumOfDigits(second->data);


				if (sum_First > sum_Second)
				{
					list::SwapNextNodes(firstRoot, secondRoot);
					std::swap(first, second);

					sum_First = sum_Second;
					PrintList(root);
					continue;
				}
				secondRoot = secondRoot->next;
			}
			firstRoot = firstRoot->next;
			secondRoot = firstRoot->next;
		}
	}
	void DeleteNextNode(Node* node)
	{
		Node* nextNode = node->next;
		node->next = nextNode->next;
		delete(nextNode);
	}
	void DuplicateNextNode(Node* node)
	{
		Node* nextNode = node->next;
		Node* duplicateNode = new Node;
		duplicateNode->data = nextNode->data;
		duplicateNode->next = nextNode->next;
		nextNode->next = duplicateNode;
	}
}