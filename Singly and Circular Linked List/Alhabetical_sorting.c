#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char data[25];
    struct node *next;
} *head = NULL, *toe;

typedef struct node NODE;

void create(int n);

void display();

void sort_alpha();

int main(void)
{
	printf("List Size : ");
	int size = 0;
	scanf("%d", &size);
	printf("\nEnter %d names\n", size);
	create(size);
	sort_alpha();
	printf("\nSorted List");
	display();
}

void create(int n)
{
    if (head == NULL)//Empty List
    {
        head = (NODE*)malloc(sizeof(NODE));
        printf("Name : ");
        char garb[10];
        gets(garb);
        gets(head->data);
        head->next = NULL;
        toe = head;
        --n;
    }

    for(int i=0; i<n; ++i)
    {
        NODE* node = (NODE*)malloc(sizeof(NODE));
        printf("Name : ");
        gets(node->data);
        node->next = NULL;//creation of a node
        toe->next = node;
        toe = node;
    }
    return;
}

void sort_alpha()
{
	for (NODE* i=head; i!=NULL; i=i->next)
	{
		for (NODE* j=head; j->next!=NULL; j=j->next)
		{
			int comp = strcmp(j->data, j->next->data);

			if(comp>0)
			{
				char temp[25];

				strcpy(temp, j->data);

				strcpy(j->data, j->next->data);

				strcpy(j->next->data, temp);
			}
		}

	}
}

void display()
{
    printf("\n=================\n");
    for ( NODE *display=head; display!=NULL; display=display->next)
    {
        printf("%s\n",display->data);
    }
    printf("\n=================\n"); 
}