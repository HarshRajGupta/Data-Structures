#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX {10};

int front {-1}, rear {-1};

bool enqueue (int* Arr) // insert at end
{
	if (rear+1 > MAX)// +1 for index 0 and +1 for new element 
	{
		return false;// false means Queue was full---Work not done
	}
	else if (front == -1 && rear == -1)
	{
		cin >> Arr[++rear]; // rear = -1 + 1 = 0
		front = rear;// More enquing will not change the front
		return true;
	}
	else
	{
		cin >> Arr[++rear]; // rear 
		return true;
	}
}

bool deque (int* Arr) // delete from begining
{
	if (front == -1 && rear == -1)
	{
		return false;// Queue is empty---Can't perform deletion in empty queue
	}
	else if (front == rear)// Deleting the last element
	{
		front = -1;
		rear = -1;
		return true;// No further deletion can be performed
	}
	else
	{
		++front;
		return true;
	}
}

void createqueue (int* Arr, int n)
{
	for(int i=0; i<n; i++)
	{
		if (enqueue(Arr) == false)
		{
			cout << "\nOVERLOADED" << endl;
			return;
		}
		else
			continue;
	}
}

int count()
{
	if (front == -1 && rear == -1)
	{
		return 0;// Queue has 0 elements
	}
	else // 10    4
	{
		return (rear - front + 1);
	}
}

void display (int* Arr)
{
	if (front == -1 && rear == -1)
	{
		cout << "EMPTY";
	}
	else
	{
		for (int i=front; i <=rear; ++i)
		{
			cout << Arr[i] << " ";
		}
	}
}