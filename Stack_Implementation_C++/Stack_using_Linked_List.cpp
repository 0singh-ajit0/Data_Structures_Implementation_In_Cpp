#include "Stack_using_Linked_List.h"

Node *Stack :: createNode()
{
	Node *newNode = new Node;
	if ( newNode == NULL )
		return NULL;

	return newNode;
}

bool Stack :: push(int data)
{
	Node *newNode = createNode();
	if ( newNode == NULL )
		return false;
	
	newNode->data = data;
	newNode->next = head->next;
	head = newNode;
	return true;
}