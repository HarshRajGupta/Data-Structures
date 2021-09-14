#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

typedef struct node NODE;

NODE* create(NODE* z)
{
	NODE *c;
	c = (NODE*)malloc(sizeof(NODE));
	scanf("%d", &c->data);
	z->next = c;
	c->next = NULL;
	return c;
}

NODE* insert(NODE* z)
{
	printf("Value of extra element : ");

	NODE* n;//New Node
	n = (NODE*)malloc(sizeof(NODE));
	int v1;
	scanf("%d", &v1);
	n->data = v1;
	n->next = NULL;

	printf("Position : ");
	int pos;
	scanf("%d", &pos);

	if (pos==0)
	{
		//exchanging new element with head
		n->next = z->next;
		z->next = n;
		n->data = z->data;
		z->data = v1;

  	  /*Inserting new node at front
		n->next = head;
		head = n;*/
		// n->next = z;
		// z = n;
	}
	else
	{
		NODE *t = z;
    	for (int i=0; i<pos-1; ++i)
			{
				t = t->next;
			}
			n->next = t->next;
			t->next = n;
	}
	return n;

}

int main(void)
{
	NODE *head = NULL;
	head = (NODE*)malloc(sizeof(NODE));
	printf("Enter ten numbers\n");
	scanf("%d",&head->data);

	NODE *L2, *L3, *L4, *L5, *L6, *L7, *L8, *L9, *L10;
	L2 = create(head);
	L3 = create(L2);
	L4 = create(L3);
	L5 = create(L4);
	L6 = create(L5);
	L7 = create(L6);
	L8 = create(L7);
	L9 = create(L8);
	L10 = create(L9);

	NODE *in;
	in = insert(head);

	NODE *cmd = head;
	while(cmd != NULL)
    {
    	printf("%d ",cmd->data );
    	cmd = cmd->next;
    }
    return 0;
}