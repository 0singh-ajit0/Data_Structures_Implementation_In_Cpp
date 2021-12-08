#include <iostream>

class Stack
{
private:
	int top = -1;
	int currentSize = 4;
	int *arr = new int[currentSize];
	void doubleArraySize();
	void copyArr(int*, int*);
public:
	bool push(int);
	int pop();
	int returnTop();
	bool isEmpty();
	bool printStack();
};
