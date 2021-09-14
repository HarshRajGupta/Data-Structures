#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;

NODE* head=NULL;

void create_list(int);

void create_at_end(NODE*);

void display(NODE*);

int main(void)
{
	printf("List Size : ");
	int n;
	scanf("%d", &n);
	printf("Enter %d Numbers\n", n);
	head = (struct node*)malloc(sizeof(struct node));
	scanf("%d", &head->data);
	head->next = NULL;
	--n;
	create_list(n);
	display(head);
	return 0;
}

void create_list(int n)
{
	for (int i=0; i<n; ++i)
	{
		create_at_end(head);
	}
}

void create_at_end(NODE* start)
{
	NODE* node=NULL;
    node = (struct node*)malloc(sizeof(struct node));
    scanf("%d", &node->data);
    node->next = NULL;

    NODE* create;
	for (create = start; create->next != NULL; create = create->next)
	{
		//TO REACH THE END OF LIST
	}
	create->next = node;
}

void display(NODE* start)
{
	printf("========================================\n");
    for ( NODE *display=start; display!=NULL; display=display->next)
    {
        printf("%d ",display->data);
    }
    printf("\n========================================");  
}