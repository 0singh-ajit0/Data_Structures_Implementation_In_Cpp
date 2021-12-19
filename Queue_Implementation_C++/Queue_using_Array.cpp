#include "Queue_using_Array.h"

bool Queue :: enqueue(int data)
{
	if ( (rear + 1) % maxSize == front )
	{
		if ( !doubleArraySize() )
			return false;
	}
	if ( front == rear == -1 )
		front = rear = 0;
	else
		rear = (rear + 1) % maxSize;

	arr[rear] = data;
	currentSize++;
	return true;
}

bool Queue :: dequeue()
{
	if ( front == -1 )
		return false;
	else if ( front == rear )
		front = rear = -1;
	else
		front = (front + 1) % maxSize;
	return true;
}

bool Queue :: doubleArraySize()
{
	int *newArr;

	maxSize *= 2;
	newArr = new int[maxSize];
	if (newArr == NULL)
	{
		cout << "\tStack Overflow\n";
		maxSize /= 2;
		return false;
	}
	copyArr(arr, newArr);
	delete[] arr;
	arr = newArr;
}

void Queue :: copyArr(int *arr, int *newArr)
{
	for (int i = 0; i < maxSize / 2; i++)
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
	if (isEmpty())
		return false;
	std::cout << "FRONT -> ";
	for (int i = front; i <= rear; i++)
		std::cout << arr[i] << std::endl;
	return true;
}

