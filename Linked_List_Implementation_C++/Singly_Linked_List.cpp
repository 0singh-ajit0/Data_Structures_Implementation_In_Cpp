#include "Singly_Linked_List.h"

Node *SinglyLinkedList :: createNode(int data)
{
	Node *node = new Node;

	if (node == NULL)
		return NULL;
	
	node->data = data;
	return node;
}

bool SinglyLinkedList :: insertNodeAtBeggining(int data)
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
	head = newNode;
	return true;
}

bool SinglyLinkedList :: insertNodeAtEnd(int data)
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
	return true;
}

bool SinglyLinkedList :: insertNodeAtLOC(int data, int loc)
{
	if ( loc < 1 )
		return false;
	
	Node *newNode, *cur = head;

	if ( !( newNode = createNode(data) ) )
		return false;

	if ( loc == 1 || head == NULL )
	{
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
	cur->next = newNode;

	return true;
}

bool SinglyLinkedList :: deleteNodeAtBeggining()
{
	if ( head == NULL )
		return false;
	
	Node *temp = head;

	head = head->next;
	delete temp;
	return true;
}

bool SinglyLinkedList :: deleteNodeAtEnd()
{
	if ( head == NULL )
		return false;
	
	Node *cur = head;
	Node *prev;

	if ( head->next == NULL )
	{
		head = NULL;
		delete cur;
		return true;
	}

	while ( cur->next != NULL )
	{
		prev = cur;
		cur = cur->next;
	}

	prev->next = NULL;
	delete cur;
	return true;
}

bool SinglyLinkedList :: deleteNodeAtLOC(int loc)
{
	if ( head == NULL || loc < 1 )
		return false;
	
	Node *cur = head;
	Node *prev;

	if ( loc == 1 )
	{
		head = head->next;
		delete cur;
		return true;
	}

	while ( --loc )
	{
		prev = cur;
		cur = cur->next;
		if ( cur == NULL )
			return false;
	}

	prev->next = cur->next;
	delete cur;
	return true;
}

bool SinglyLinkedList :: isEmpty()
{
	if ( head == NULL)
		return true;
	return false;
}

int SinglyLinkedList :: listLength()
{
	int length = 0;
	Node *cur = head;

	while ( cur != NULL )
	{
		length++;
		cur = cur->next;
	}

	return length;
}

void SinglyLinkedList :: printLinkedList()
{
	if ( head == NULL )
	{
		std::cout << "\t\tLinked List is Empty\n";
		return;
	}
	Node *cur = head;

	while ( cur != NULL )
	{
		std::cout << cur->data << " ";
		cur = cur->next;
	}
	
	std::cout << std::endl;
}


int main()
{
	SinglyLinkedList sll;

	sll.insertNodeAtBeggining(20);
	sll.insertNodeAtLOC(1000, 1);
	sll.insertNodeAtEnd(-9);
	sll.insertNodeAtEnd(99);
	sll.insertNodeAtEnd(39);

	sll.deleteNodeAtBeggining();
	sll.deleteNodeAtEnd();
	sll.deleteNodeAtLOC(2);
	sll.deleteNodeAtLOC(1);
	
	sll.printLinkedList();

	return 0;
}