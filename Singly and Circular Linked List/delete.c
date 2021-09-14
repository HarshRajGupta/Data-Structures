#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* next;
} *head = NULL, *end;

typedef struct node NODE;

void createList(int n)
{
    if (n < 0)
    {
        printf("invalid command");
        exit(0);
    }

    if(n == 0)
        return;

    else
    {
        NODE* node = (NODE*)malloc(sizeof(NODE));
        scanf("%d", &node->data);
        node->next = NULL;

        if(head == NULL)
        {
            head = node;//List started
            end = head;//end will connect nodes
        }
        else
        {
            end->next = node;//end connected the new node
            end = node;//end again becomes the last node
        }   
        createList(n-1);//Recursion Call
    }
}

size_t count()
{
    int count=0;
    for (NODE *cnt=head; cnt!=NULL;  cnt=cnt->next)
        ++count;
    return count;
}

void display()
{
    printf("\n========================================\n");

    for ( NODE *display=head; display!=NULL; display=display->next)
        printf("%d ",display->data);

    // NODE* display = head;
    // for ( int i=0; i<count(); ++i)
    // {
    // 	printf("%d ", display->data);
    // 	display = display->next;
    // }

    printf("\n========================================\n");
}

void deletebyposition()
{
	int pos;
	scanf("%d",&pos);

	pos = (pos <= count()) ? pos : count();//OverFlow
    pos = (pos > 0) ? pos : 1;//UnderFlow

	if (pos == 1)
	{
		NODE* temp = head->next;//Storing address of next node
        free(head);//Deleting the memory allocated
        head = temp;//Restoring the breaked list
	}
	else
	{
		NODE* t = head;//i=0
		for (int i=1; i<pos-1; ++i)
            t = t->next;
		NODE* temp = t->next->next;
        free(t->next);
        t->next = temp;
	}
}

void deletebyvalue()
{
    int value;
    scanf("%d", &value);

    if (value == head->data)
    {
        NODE* temp = head->next;
        free(head);
        head = temp;
    }
    else
    {
        NODE* t = head;
        while (t->next->data != value && t->next->next != NULL)
                t = t->next;

        if(t->next->data == value)
        {
            NODE* temp = t->next->next;
            free(t->next);
            t->next = temp;
        }
        else
        	printf("Number not found\n");
    }
}

int main(void)
{
	printf("List size : ");
	int size=0;
	scanf("%d", &size);
	printf("Enter Elements\n");
	createList(size);
	display();
	printf("Postion to delete : ");
	deletebyposition();
	int new_size = count();
	printf("\nNew Size = %d", new_size);
	display();
	printf("Value to delete : ");
	deletebyvalue();
	new_size = count();
	printf("\nNew Size = %d", new_size);
	display();
	free(head);
	free(end);
	return 0;
}