#include <iostream>
using namespace std;

struct node
{
    int data {0};
    struct node *next {NULL};
} *head = NULL;

typedef struct node NODE;

void push(int value)
{
	NODE* new_node = (NODE*)malloc(sizeof(NODE));
	new_node->data = value;
	new_node->next = head;
	head = new_node;
}

int fac(int n)
{
	if(n==1)
	{
		push(1);
		return 1;
	}
	else
	{
		push(n);
		return(n*fac(n-1));
	}
}

int check()
{
	int check {1};
	NODE* i = head;
	while(i != NULL)
	{
		check *= i->data;
		i = i->next;
	}
	return check;
}

void display()
{
	printf("\n========================================\n");

	for(NODE* display=head; display!=NULL; display=display->next)
		cout << display->data << " ";

	printf("\n========================================\n");
}

int main(void)
{
	cout << "Number : ";
	int n;
	cin >> n;
	n = fac(n);
	cout << "Factorial(via recursion) = " << n;
	cout << "\n\nValues Stored in the Stack";
	display();
	cout << "Product of Stack = " << check();
	return 0;
}