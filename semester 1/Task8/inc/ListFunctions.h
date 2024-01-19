#pragma once
#include <iostream>

struct Node
{
	int data;
	Node* next;
};

namespace list
{
	void SwapNextNodes(Node* first, Node* second);

	void PrintList(Node* root);
}