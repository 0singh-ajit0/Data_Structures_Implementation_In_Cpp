#include <iostream>

struct Node
{
	int data;
	Node *next = NULL;
};

class Queue
{
private:
	int *front = NULL;
	int *rear = NULL;
	int size = 0;
	Node *createNode(int);
public:
	bool enqueue(int);
	bool dequeue();
	int returnFront();
	bool isEmpty();
	bool printQueue();
};