#pragma once
#include <iostream>
#include <Functions.h>

struct Node
{
	int data;
	Node* next;
};

namespace list
{
	void SwapNextNodes(Node* first, Node* second);

	void PrintList(Node* root);

	void SortList(Node* root);

	void DeleteNextNode(Node* node);

	void DuplicateNextNode(Node* node);
}