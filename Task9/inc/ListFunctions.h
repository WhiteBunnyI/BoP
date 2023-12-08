#pragma once
#include <iostream>

struct Node
{
	int data;
	Node* next;
	Node* prev;
};

namespace list
{
	void PrintForward(Node* root);

	void SwapNode(Node* root, Node* first, Node* second);

	void PrintBack(Node* root);

	void DeleteNode(Node* root, Node* node);

	void DuplicateNode(Node* node);
}