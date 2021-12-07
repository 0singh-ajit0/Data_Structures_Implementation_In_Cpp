#include <iostream>

struct Node
{
	int data;
	Node *next = NULL;
};

class CircularLinkedList
{
private:
	Node *head = NULL;
	Node *createNode(int);
public:
	bool insertNodeAtBeggining(int);
	bool insertNodeAtEnd(int);
	bool insertNodeAtLOC(int, int);

	bool deleteNodeAtBeggining();
	bool deleteNodeAtEnd();
	bool deleteNodeAtLOC(int);

	bool isEmpty();
	int listLength();

	void printLinkedList();
};