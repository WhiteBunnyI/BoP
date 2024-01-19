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
}