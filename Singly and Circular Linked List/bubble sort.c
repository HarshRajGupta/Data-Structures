#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL, *ptr;

typedef struct node NODE;

void createList(int n);

void display();

void bubble();

int main(void)
{
	printf("List Size : ");
	int n;
	scanf("%d", &n);
	printf("Enter %d Numbers\n", n);
	createList(n);
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

void display()
{
    printf("\n========================================\n");
    for ( NODE *display=head; display!=NULL; display=display->next)
    {
        printf("%d ",display->data);
    }
    printf("\n========================================\n"); 

}

void bubble()
{
	for (NODE* i=head; i!=NULL; i=i->next)
	{
		for (NODE* j=head; j->next!=NULL; j=j->next)
		{
			if (j->data > j->next->data)
			{
				int temp;
				temp = j->data;
				j->data = j->next->data;
				j->next->data = temp;
			}
		}
	}
}