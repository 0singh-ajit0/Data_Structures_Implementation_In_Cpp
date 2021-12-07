#include <iostream>

struct Node
{
	int data;
	Node *next = NULL;
};

class Stack
{
private:
	int top = -1;
	Node *head = NULL;
	Node *createNode();
public:
	bool push(int);
	int pop();
	int printTop();
	bool printStack();
};