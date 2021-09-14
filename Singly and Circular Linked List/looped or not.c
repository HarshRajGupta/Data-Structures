#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL, *ptr;

typedef struct node NODE;

bool check_loop()
{
	NODE* check = head;
	while (check != NULL)
	{
		for (NODE* i=check->next; i!=NULL; i=i->next)
		{
			if (i == check)
			{
				return TRUE;
			}
		}
	}
	return FALSE;
}