#include "Queue_using_Linked_List.h"

Node *Queue :: createNode(int data)
{
	Node *newNode = new Node;
	if (newNode == NULL)
		return NULL;
	newNode->data = data;
	return newNode;
}

bool Queue :: enqueue(int data)
{
	Node *newNode;
	if ( !(newNode = createNode) )
		return false;
	if ( front == NULL )
		front = rear = newNode;
	else
	{
		rear->next = newNode;
		rear = newNode;
	}
	return true;
}

bool Queue :: dequeue()
{
	Node *temp;
	if (front == NULL)
		return false;

	temp = front;
	front = front->next;
	delete temp;
	return true;
}

int Queue :: returnFront()
{
	if (isEmpty())
		return -1;
	return front->data;
}

bool Queue :: isEmpty()
{
	if (front == NULL)
		return true;
	return false;
}

bool Queue :: printQueue()
{
	Node *cur = front;
	if (isEmpty())
		return false;

	std::cout << "FRONT |\n\t  v\n";
	while (cur != NULL)
	{
		std::cout << cur->data << " ";
		cur = cur->next;
	}
	std::cout << std::endl;
	return true;
}