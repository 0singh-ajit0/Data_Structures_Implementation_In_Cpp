#include <iostream>

class Queue
{
private:
	int front = -1;
	int rear = -1;
	int maxSize = 4;
	int *arr = new int[maxSize];
	bool doubleArraySize();
	void copyArr(int*, int*);
public:
	bool enqueue(int);
	bool dequeue();
	int returnFront();
	bool isEmpty();
	bool printQueue();
};