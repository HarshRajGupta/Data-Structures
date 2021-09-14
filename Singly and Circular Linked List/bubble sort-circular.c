#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL, *ptr;

typedef struct node NODE;

void createList(int n);

void make_circular();

void display();

void bubble();

int main(void)
{
	printf("List Size : ");
	int n;
	scanf("%d", &n);
	printf("Enter %d Numbers\n", n);
	createList(n);
    make_circular();
	bubble();
	display();
	return 0;
}

void createList(int n)
{
    if(n == 0)
        return;

    else
    {
        NODE *node;
        node = ((NODE*)malloc(sizeof(NODE)));
        scanf("%d",&node->data);

        node->next = NULL;
        if(head == NULL)
        {
            head = node;
            ptr = head;
        }
        else
        {
            ptr->next = node;
            ptr = node;
        }   
        createList(n-1);
    }
}

void make_circular()
{
    NODE *circular = head;
    while (circular->next != NULL)
    {
        circular = circular->next;
    }
    circular->next = head;
}

void display()
{
    printf("\n========================================\n");
    NODE *display=head;
    do
    {
        printf("%d ",display->data);
        display=display->next;

    }while(display!=head);

    printf("\n========================================\n"); 

}

void bubble_circular()
{
    NODE* i=head;
	do {
        NODE* j=head;
		do {
			if (j->data > j->next->data)
			{
				int temp;
				temp = j->data;
				j->data = j->next->data;
				j->next->data = temp;
			}
            j=j->next;

		} while ( j->next!=head);

        i=i->next;

	} while ( i!=head);
}