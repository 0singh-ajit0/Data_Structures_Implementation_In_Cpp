#include <iostream>

struct Node
{
	int data;
	Node *next = NULL;
};

class Stack
{
private:
	Node *top = NULL;
	Node *createNode();
public:
	bool push(int);
	int pop();
	Node *returnTop();
	bool printStack();
};