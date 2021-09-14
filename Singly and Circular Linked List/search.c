#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL, *ptr;

typedef struct node NODE;

void createList(int);

int count();

int linear(int);

int main(void)
{
    int n;
    printf("List Size : ");
    scanf("%d",&n);
    createList(n);
    printf("Number to SEARCH for : ");
    int search;
    scanf("%d", &search);
    int pos;
    pos = linear(search);
    printf("%d is located at Position %d", search, pos );
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

        printf("Data : ");
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

int count()
{
    int count=0;
    NODE* c = head;
    while (c != NULL)
    {
        ++count;
        c = c->next;
    }
    return count;
}

int linear(int search)
{
    int pos=0;
    NODE* identify = head;
    while (identify != NULL)
    {
        ++pos;

        if (identify->data == search)
            return pos;

        identify = identify->next;
    }
    return 0;
}
