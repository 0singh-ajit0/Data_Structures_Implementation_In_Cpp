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
	newNode->next = top;
	top = newNode;
	return true;
}

int Stack :: pop()
{
	int popped_item;
	Node *temp;

	if ( top == NULL)
	{
		std::cout << "\t\tStack is empty\n" << std::endl;
		return -1;
	}	
	temp = top;
	popped_item = top->data;
	top = top->next;
	delete temp;
	return popped_item;
}

Node *Stack :: returnTop()
{
	return top;
}

bool Stack :: printStack()
{
	Node *cur = top;

	if ( top == NULL )
		return false;
	
	std::cout << "TOP -> ";
	while ( cur != NULL )
	{
		std::cout << cur->data << "\n       ";
		cur = cur->next;
	}
	std::cout << std::endl;
	return true;
}

int main()
{
	Stack s;

	s.push(3);
	s.push(31);
	s.push(180);
	s.push(-9);

	s.pop();
	s.pop();
	
	s.printStack();
	std::cout << std::endl;
	return 0;
}