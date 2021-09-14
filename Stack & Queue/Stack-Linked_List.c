#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
	int data;
	struct node *next;
} *head = NULL, *end = NULL;

typedef struct node NODE;

void push()
{
	NODE* new_node = (NODE*)malloc(sizeof(NODE));
	scanf("%d", &new_node->data);
	new_node->next = head;
	head = new_node;
}

bool pop()
{
	if (head != NULL)
	{
		NODE* temp = head->next;
		free(head);
		head = temp;
		return true;
	}
	else
		return false;
}

void createstack(int n)
{
	if (n <= 0)
		return;
	else
	{
		push();

		createstack(n - 1);
	}
}

void display()
{
	printf("\n========================================\n");

	if (head != NULL)
	{
		for (NODE* display = head; display != NULL; display = display->next)
		{
			printf("%d ", display->data);
		}
	}
	else if (head == NULL)
		printf("Stack is Empty\n");

	printf("\n========================================\n");
}

int main(void)
{
	int ch = 0;
	while (ch != 5)
	{
		printf("1.Createsatck\n2.Push\n3.Pop\n4.Display\n5.Exit\n");
		printf("Enter your Choice : ");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1: printf("\nStack Size : ");
		        int n = 0;
		        printf("Enter %d Numbers\n", n);
		        createstack(n);
		        printf("\n");
		        break;

		case 2: printf("\nEnter Number : ");
    			push();
    			printf("\n");
	    		break;

		case 3: if (pop() == true)
    			{
	    			printf("\nDone Succesfully\n\n");
		    	}
			    else
    			{
	    			printf("\nStack is empty\n\n");
		    	}
		    	break;

		case 4: display();
		    	break;

		case 5: printf("Thank You");
		    	break;

		default:printf("Wronng Choice\nPlease Select the correct one\n\n");
		    	break;
		}
	}
	return 0;
}