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

int count();

void insert();

void deletebyposition();

int main(void)
{
    printf("List Size : ");
    int n;
    scanf("%d", &n);
    printf("Enter Elements\n");
    createList(n);
    display();
    insert();
    display();
    printf("Position to delete : ");
    deletebyposition();
    int new_size = count();
    printf("\nNew Size = %d", new_size);
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

int count()
{
    int count=0;
    for (NODE *cnt=head; cnt!=NULL;  cnt=cnt->next)
    {
        ++count;
    }
    return count;
}

void insert()
{
    printf("Value of extra element : ");

    NODE* new = (NODE*)malloc(sizeof(NODE));
    scanf("%d", &new->data);
    new->next = NULL;

    printf("Position : ");
    int pos;
    scanf("%d", &pos);
    pos = (pos <= count()) ? pos : count();

    if (pos==0)
    {
        new->next = head;
        head = new;
    }
    else
    {
        NODE *t = head;
        for (int i=0; i<pos-1; ++i)
            t = t->next;
        new->next = t->next;
        t->next = new;
    }
}

void deletebyposition()
{
    int pos;
    scanf("%d",&pos);

    if (pos == 1)
    {
        NODE* temp = head->next;
        free(head);
        head = temp;
    }
    else
    {
        NODE* t = head;
        int i=0;
        while (i<pos-2 && t->next->next != NULL)
        {
                t = t->next;
                ++i;
        }
        NODE* temp = t->next->next;
        free(t->next);
        t->next = temp;
    }
}