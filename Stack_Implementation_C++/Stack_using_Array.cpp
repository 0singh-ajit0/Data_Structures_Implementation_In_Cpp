#include "Stack_using_Array.h"

bool Stack :: push(int data)
{
	if ( top == (currentSize - 1) )
		doubleArraySize();

	arr[++top] = data;
	return true;
}

int Stack :: pop()
{
	if ( top == -1 )
	{
		std::cout << "\t\tStack is empty\n";
		return -1;
	}
	return arr[top--];
}

int Stack :: returnTop()
{
	return top;
}

bool Stack :: isEmpty()
{
	if ( top == -1 )
		return true;
	return false;
}

bool Stack :: printStack()
{
	int temp = top;
	if ( top == -1 )
		return false;

	std::cout << "Top -> ";
	while ( temp >= 0 )
	{
		std::cout << arr[temp] << "\n       ";
		temp--;
	}
	std::cout << std::endl;
	return true;
}

void Stack :: doubleArraySize()
{
	int *newArr;

	currentSize *= 2;
	newArr = new int[currentSize];
	copyArr(arr, newArr);
	delete[] arr;
	arr = newArr;
}

void Stack :: copyArr(int *oldArr, int *newArr)
{
	for (int i = 0; i < currentSize / 2; i++)
		newArr[i] = oldArr[i];
}

int main()
{
	Stack s;

	s.push(10);
	s.push(-12);
	s.push(100);
	s.push(100);
	s.push(21);

	s.printStack();
	return 0;
}