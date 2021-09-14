#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

typedef struct node NODE;

int main(void)
{
	NODE *L1=NULL;
	NODE *L2=NULL;
    NODE *L3=NULL;
	NODE *L4=NULL;
	NODE *end=NULL;

	L1=(NODE*)malloc(sizeof(NODE));
	L2=(NODE*)malloc(sizeof(NODE));
	L3=(NODE*)malloc(sizeof(NODE));
	L4=(NODE*)malloc(sizeof(NODE));
	end=(NODE*)malloc(sizeof(NODE));

	L1->next = L2;
	L2->next = L3;
	L3->next = L4;
	L4->next = end;
	end->next = NULL;

	NODE *cmd = L1;
    printf("Enter Elements\n");
	while(cmd != NULL)
	{
		scanf("%d", &cmd->data);
		cmd = cmd->next;
	}
	cmd = L1;

    while(cmd != NULL)
    {
    	printf("%d ",cmd->data );
    	cmd = cmd->next;
    }
    return 0;
}