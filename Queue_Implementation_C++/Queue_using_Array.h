#include <iostream>

class Queue
{
private:
	int front = -1;
	int rear = -1;
	int currentSize = 4;
	int *arr = new int[currentSize];
	void doubleArraySize();
	void copyArr(int*, int*);
public:
	bool enqueue(int);
	int pop();
	int returnFront();
	bool isEmpty();
	bool printQueue();
};