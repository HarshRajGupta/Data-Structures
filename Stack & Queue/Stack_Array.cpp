#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX {100};

int top = -1;

bool push(int* Arr)
{
	if (top < MAX)
	{
		int n;
		scanf("%d", &n);
		++top;
		*(Arr + top) = n;
		return true;
	}
	else
		return false;
}

bool pop(int* Arr)
{
	if (top >= 0)
	{
		top--;
		return true;
	}
	else
		return false;
}

void display(int Arr[])
{
	if (top >= 0)
	{
		printf("\n========================================\n");

		for (int i = 0; i <= top; ++i)
		{
			printf("%d ", Arr[i]);
		}

		printf("\n========================================\n");
	}
	else
		printf("Stack is empty\n");
}

int main(void)
{
	int ch = 0;
	int Arr[MAX];
	while (ch != 4)
	{
		printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1: printf("data to push : ");
		    	if (push(Arr) == true)
		    	{
     				printf("Done Succesfully\n");
		    	}
	    		else
	    		{
		    		printf("Stack is full\n");
	    		}
			    break;

		case 2: if (pop(Arr) == true)
		        {
     				printf("Done Succesfully\n");
		        }
	    		else
	    		{
		    		printf("Stack is empty\n");
	    		}
			    break;

		case 3: display(Arr);
    			break;

		case 4: printf("Thank You\n");
	    		break;

		default:printf("Wronng Choice\nPlease Select the correct one\n");
		        break;
		}
	}
	return 0;
}