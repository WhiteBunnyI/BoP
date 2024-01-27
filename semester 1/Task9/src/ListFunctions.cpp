#include <ListFunctions.h>

namespace list
{
	void PrintForward(Node* root)
	{
		Node* current = root->next;

		do
		{
			std::cout << current->data << " ";
			current = current->next;
		} while (root->next != current);

		std::cout << '\n';
	}

	void PrintBack(Node* root)
	{
		Node* current = root->next;

		do
		{
			std::cout << current->data << " ";
			current = current->prev;
		} while (root->next != current);

		std::cout << '\n';
	}


	void SwapNode(Node* root, Node* first, Node* second)
	{
		if (first == root->next) root->next = second;
		else if (second == root->next) root->next = first;

		std::swap(first->prev, second->prev);
		std::swap(first->prev->next, second->prev->next);
		std::swap(first->next->prev, second->next->prev);
		std::swap(first->next, second->next);
	}

	void DeleteNode(Node* root, Node* node)
	{
		node->next->prev = node->prev;
		node->prev->next = node->next;

		if (root->next == node) root->next = node->prev;
		delete(node);
	}

	void DuplicateNode(Node* node)
	{
		Node* newNode = new Node;
		newNode->data = node->data;
		newNode->next = node->next;
		newNode->prev = node;
		node->next->prev = newNode;
		node->next = newNode;

	}
}