#include "Queue_using_Array.h"

bool Queue :: enqueue(int data)
{
	if ( rear == currentSize - 1 )
		doubleArraySize();
	if ( front == rear == -1 )
	{
		front = rear = 0;
		arr[rear] = data;
		return true;
	}
	arr[++rear] = data;
	return true;
}

int Queue :: pop()
{
	if ( front == currentSize - 1 )
		return -1;
	return arr[front++];
}


void Queue :: doubleArraySize()
{
	int *newArr;

	currentSize *= 2;
	newArr = new int[currentSize];
	copyArr(arr, newArr);
	delete[] arr;
	arr = newArr;
}

void Queue :: copyArr(int *arr, int *newArr)
{
	for (int i = 0; i < currentSize / 2; i++)
		newArr[i] = arr[i];
}

int Queue :: returnFront()
{
	if (front == -1)
		return 0;
	return arr[front];
}

bool Queue :: isEmpty()
{
	if ( front = -1 )
		return true;
	return false;
}

bool Queue :: printQueue()
{
	std::cout << "FRONT -> ";
	for (int i = front; i <= rear; i++)
	{
		std::cout << arr[i] << std::endl;
	}
}

