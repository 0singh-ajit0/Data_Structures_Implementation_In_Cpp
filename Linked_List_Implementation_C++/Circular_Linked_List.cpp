#include "Circular_Linked_List.h"

Node *CircularLinkedList :: createNode(int data)
{
	Node *temp = new Node;

	if ( temp == NULL )
		return NULL;
	
	temp->data = data;
	return temp;
}

bool CircularLinkedList :: insertNodeAtBeggining(int data)
{
	Node *newNode, *cur;

	if ( !( newNode = createNode(data) ) )
		return false;
	
	if ( head == NULL )
	{
		newNode->next = newNode;
		head = newNode;
		return true;
	}

	cur = head;
	while ( cur->next != head )
		cur = cur->next;
	
	cur->next = newNode;
	newNode->next = head;
	head = newNode;
	return true;
}

bool CircularLinkedList :: insertNodeAtEnd(int data)
{
	Node *newNode, *cur;

	if ( !( newNode = createNode(data) ) )
		return false;
	
	if ( head == NULL )
	{
		newNode->next = newNode;
		head = newNode;
		return true;
	}

	cur = head;
	while ( cur->next != head )
		cur = cur->next;

	cur->next = newNode;
	newNode->next = head;
	return true;
}

bool CircularLinkedList :: insertNodeAtLOC(int data, int loc)
{
	Node *newNode, *cur;

	if ( loc < 1 )
		return false;
	
	if ( !( newNode = createNode(data) ) )
		return false;
	
	cur = head;
	if ( loc == 1 )
	{
		while ( cur->next != head )
			cur = cur->next;
		
		cur->next = newNode;
		newNode->next = head;
		head = newNode;
		return true;
	}

	while ( --loc > 1 )
	{
		cur = cur->next;
		if ( cur == head )
			return false;
	}

	newNode->next = cur->next;
	cur->next = newNode;
	return true;
}

bool CircularLinkedList :: deleteNodeAtBeggining()
{
	Node *temp;

	if ( head == NULL )
		return false;
	
	if ( head->next == head )
	{
		delete head;
		head = NULL;
		return true;
	}

	temp = head;
	while ( temp->next != head )
		temp = temp->next;
	
	temp->next = temp->next->next;
	delete head;
	head = temp->next;
	return true;
}

bool CircularLinkedList :: deleteNodeAtEnd()
{
	Node *cur, *prev;

	if ( head == NULL )
		return false;
	
	if ( head->next == head )
	{
		delete head;
		head = NULL;
		return true;
	}

	cur = head;
	while ( cur->next != head )
	{
		prev = cur;
		cur = cur->next;
	}
	
	prev->next = head;
	delete cur;
	return true;
}

bool CircularLinkedList :: deleteNodeAtLOC(int loc)
{
	Node *cur, *prev;

	if ( head == NULL || loc < 1 )
		return false;
	
	cur = head;
	if ( loc == 1 )
	{
		if ( head->next == head )
		{
			delete head;
			head = NULL;
			return true;
		}
		while ( cur->next != head )
			cur = cur->next;
		
		cur->next = cur->next->next;
		delete head;
		head = cur->next;
		return true;
	}

	while ( --loc )
	{
		prev = cur;
		cur = cur->next;
		if ( cur == head )
			return false;
	}
	prev->next = cur->next;
	delete cur;
	return true;
}


void CircularLinkedList :: printLinkedList()
{
	Node *cur = head;

	do
	{
		std::cout << cur->data << " ";
		cur = cur->next;
	} while ( cur != head );
	std::cout << std::endl;
}


int main()
{
	CircularLinkedList cll;

	cll.deleteNodeAtBeggining();
	cll.insertNodeAtEnd(1000);
	cll.deleteNodeAtBeggining();
	cll.insertNodeAtBeggining(12);
	cll.insertNodeAtEnd(90);
	cll.insertNodeAtBeggining(34);
	cll.insertNodeAtLOC(10, 1);
	cll.insertNodeAtBeggining(-100);
	cll.deleteNodeAtBeggining();
	cll.printLinkedList();

	cll.deleteNodeAtLOC(1);

	cll.printLinkedList();
	
	return 0;
}