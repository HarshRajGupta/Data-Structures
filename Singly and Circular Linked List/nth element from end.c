#include<stdio.h>
#include<stdlib.h>
#include<process.h>

struct node
{
    int data;
    int frequency;
    struct node *next;
} *head = NULL, *ptr;

typedef struct node NODE;

void createList(int);

int count();

int elementbyposition(int);

int main(void)
{
    int n;
    printf("List Size : ");
    scanf("%d",&n);
    createList(n);
    int pos;
    printf("Enter position (from end) of data : ");
    scanf("%d", &pos);
    int value;
    value = elementbyposition(pos);
    printf("%d is the value located at position %d",value, pos);
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

int elementbyposition(int n)
{
    n = count() - n;
    if(n<0)
    {
        printf("Invalid Value\n");
        exit(0);
    }
    else
    {
        NODE* mid = head;
        for (int i=1; i<n; ++i)
        {
            if (mid == NULL)
                break;
            else
                mid = mid->next;
        }
        return mid->data;
    }
}