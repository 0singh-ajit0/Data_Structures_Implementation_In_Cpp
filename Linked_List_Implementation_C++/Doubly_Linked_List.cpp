#include "Doubly_Linked_List.h"

Node *DoublyLinkedList :: createNode(int data)
{
	Node *node = new Node;

	if (node == NULL)
		return NULL;
	
	node->data = data;
	return node;
}

bool DoublyLinkedList :: insertNodeAtBeggining(int data)
{
	Node *newNode;
	if ( !( newNode = createNode(data) ) )
		return false;

	if ( head == NULL )
	{
		head = newNode;
		return true;
	}

	newNode->next = head;
	head->prev = newNode;
	head = newNode;
	return true;
}

bool DoublyLinkedList :: insertNodeAtEnd(int data)
{
	Node *newNode, *cur = head;
	if ( !( newNode = createNode(data) ) )
		return false;
	
	if ( head == NULL )
	{
		head = newNode;
		return true;
	}

	while ( cur->next != NULL )
		cur = cur->next;
	
	cur->next = newNode;
	newNode->prev = cur;
	return true;
}

bool DoublyLinkedList :: insertNodeAtLOC(int data, int loc)
{
	Node *cur = head, *newNode;

	if ( loc < 1 )
		return false;
	
	if ( !( newNode = createNode(data) ) )
		return false;
	
	if ( head == NULL )
	{
		head = newNode;
		return true;
	}
	
	if ( loc == 1 )
	{
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
		return true;
	}

	while ( --loc > 1 )
	{
		cur = cur->next;
		if ( cur == NULL )
			return false;
	}

	newNode->next = cur->next;
	newNode->prev = cur;
	if ( cur->next )
		cur->next->prev = newNode;
	
	cur->next = newNode;
	return true;
}

bool DoublyLinkedList :: deleteNodeAtBeggining()
{
	Node *temp = head;

	if ( head == NULL )
		return false;

	head = head->next;
	if ( head )
		head->prev = NULL;

	delete temp;
	return true;
}

bool DoublyLinkedList :: deleteNodeAtEnd()
{
	Node *cur = head;

	if ( head == NULL )
		return false;
	
	if ( head->next == NULL )
	{
		head = NULL;
		delete cur;
		return true;
	}

	while ( cur->next != NULL )
		cur = cur->next;
	
	cur->prev->next = NULL;
	delete cur;
	return true;
}

bool DoublyLinkedList :: deleteNodeAtLOC(int loc)
{
	Node *cur = head;

	if ( loc < 1 || head == NULL )
		return false;
	
	if ( loc == 1 )
	{
		head = head->next;
		if ( head )
			head->prev = NULL;
		delete cur;
		return true;
	}

	while ( --loc )
	{
		cur = cur->next;
		if ( cur == NULL )
			return false;
	}

	cur->prev->next = cur->next;
	if ( cur->next )
		cur->next->prev = cur->prev;

	delete cur;
	return true;
}

bool DoublyLinkedList :: isEmpty()
{
	if ( head == NULL )
		return true;
	
	return false;
}

int DoublyLinkedList :: listLength()
{
	Node *cur = head;
	int length = 0;

	while ( cur != NULL )
	{
		length++;
		cur = cur->next;
	}

	return length;
}

void DoublyLinkedList :: printLinkedList()
{
	Node *cur = head;
	if ( head == NULL )
	{
		std::cout << "\t\tLINKED LIST IS EMPTY\n";
		return;
	}

	while ( cur != NULL )
	{
		std::cout << cur->data << " ";
		cur = cur->next;
	}
	std::cout << std::endl;
}


int main()
{
	DoublyLinkedList dll;

	dll.insertNodeAtBeggining(12);
	dll.insertNodeAtEnd(-90);
	dll.deleteNodeAtBeggining();
	dll.insertNodeAtEnd(1);
	dll.insertNodeAtEnd(123);
	dll.insertNodeAtLOC(20, 4);
	dll.deleteNodeAtEnd();
	dll.printLinkedList();
	dll.deleteNodeAtLOC(2);
	

	dll.printLinkedList();
	
	return 0;
}