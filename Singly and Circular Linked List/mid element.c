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

int mid();

int main(void)
{
    int n;
    printf("List Size : ");
    scanf("%d",&n);
    createList(n);
    int mid_value;
    mid_value = mid();
    printf("%d is the mid value", mid_value);
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

int mid()
{
    int n;
    n = count();
    n = n/2;
    NODE* mid = head;
    for (int i=0; i<n; ++i)
    {
        mid = mid->next;
    }
    n = mid->data;

    return n;
}