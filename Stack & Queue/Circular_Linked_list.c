#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
}*head = NULL, *tail;

typedef struct node NODE;

void create(int n)
{
	if (head == NULL)
	{
		head = (NODE*)malloc(sizeof(NODE));
		scanf("%d", &head->data);
		head->next = NULL;
		tail = head;
		--n;
	}

	for (int i = 0; i < n; ++i)
	{
		NODE* node = (NODE*)malloc(sizeof(NODE));
		scanf("%d", &node->data);
		node->next = NULL;
		tail->next = node;
		tail = node;
	}

	tail->next = head; // Converted Singly Linked List to Circular Linked List
}

void display()
{
	printf("\n++++----++++----++++----++++----++++\n");

	for (NODE* i = head; i->next != head; i = i->next)
	{
		printf("%d => ", i->data);
	} printf("%d => ", tail->data);

	printf("\n++++----++++----++++----++++----++++\n");
}

int count()
{
	size_t count = 0;
	if (head == NULL && tail == NULL)
		return 0;
	
	else 
	{
		NODE* i = head;
		do {
			++count;
			i = i->next;
		} while (i != head);
		return count;
	}
}