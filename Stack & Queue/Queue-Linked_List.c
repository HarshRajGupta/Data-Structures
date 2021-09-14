#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

struct node
{
	int data;
	struct node *next;
} *front = NULL, *rear;

typedef struct node queue;

void enqueue()// Insertion at the End
{
	if (front == NULL)// Empty list
	{
		front = (queue*)malloc(sizeof(queue));
		scanf("%d", &front->data);
		front->next = NULL;
		rear = front;
	}
	else
	{
		queue* new_node = (queue*)malloc(sizeof(queue));
		scanf("%d", &new_node->data);
		new_node->next = NULL;
		rear->next = new_node;
		rear = new_node;
	}
}

bool dequeue()// Deletion at Begining
{
	if (front != NULL)
	{
		queue* temp = front->next;
		free(front);
		front = temp;
		return true;
	}
	else if (front == rear)// Deleting the last element
	{
		free(front);
		return true;
	}
	else
		return false;// false means list is empty >>> work not done
}

void createqueue(int n)
{
	for (int i=0; i<n; ++i)
	{
		enqueue();
	}
}

void display()
{
	printf("\n========================================\n");

	for (queue* display = front; display != NULL; display = display->next)
	{
		printf("%d ", display->data);
	}

	printf("\n========================================\n");
}

int main(void)
{
	int ch = 0;
	while (ch != 5)
	{
		printf("1.Create Queue\n2.Enqueue\n3.Dequeue\n4.Display\n5.Exit\n");
		printf("Enter your Choice : ");
		scanf("%d", &ch);

		int n = 0;
		switch (ch)
		{
		case 1: printf("\nQueue Size : ");
		        scanf("%d", &n);
		        printf("Enter %d Numbers\n", n);
		        createqueue(n);
		        printf("\n");
		        break;

		case 2: printf("\nEnter Number : ");
    			enqueue();
    			printf("\n");
	    		break;

		case 3: if (dequeue() == true)
    			{
	    			printf("\nDone Succesfully\n\n");
		    	}
			    else
    			{
	    			printf("\nQueue is empty\n\n");
		    	}
		    	break;

		case 4: display();
		        printf("\n");
		    	break;

		case 5: printf("\nThank You\n");
		    	break;

		default:printf("Wronng Choice\nPlease Select the correct one\n\n");
		    	break;
		}
	}
	return 0;
}