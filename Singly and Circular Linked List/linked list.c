#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL, *toe;

typedef struct node NODE;

NODE* create_node(NODE*);

void create(int n);

void createList(int n);

void display();

size_t count();

void insert();

void deletebyposition();

void deletebyvalue();

size_t linear(int);

int value_at_position(size_t);

int value_at_end_position(int);

int mid();

int main(void)
{
    /*
        ENTER CODE HERE
    */
    return 0;
}

NODE* create_node(NODE* previous)
{
    NODE *create = (NODE*)malloc(sizeof(NODE));
    scanf("%d", &create->data);
    previous->next = create;// linking to previous node
    create->next = NULL;// Ending (or Breaking) the list
    return create;
}

void create(int n)
{
    if (head == NULL)//Empty List
    {
        head = (NODE*)malloc(sizeof(NODE));
        scanf("%d", &head->data);
        head->next = NULL;
        toe = head;
        --n;
    }

    for (int i = 0; i < n; ++i)
    {
        NODE* node = (NODE*)malloc(sizeof(NODE));
        scanf("%d", &node->data);
        node->next = NULL;//creation of a node
        toe->next = node;
        toe = node;
    }
    return;
}

void createList(int n)
{
    if (n <= 0)
        return;

    else
    {
        NODE* node = (NODE*)malloc(sizeof(NODE));
        scanf("%d", &node->data);
        node->next = NULL;

        if (head == NULL)
        {
            head = node;//List started
            toe = head;//end will connect nodes
        }
        else
        {
            toe->next = node;//end connected the new node
            toe = node;//end again becomes the last node
        }
        createList(n - 1); //Recursion Call
    }
}

void display()
{
    printf("\n========================================\n");
    for ( NODE *display = head; display != NULL; display = display->next)
    {
        printf("%d ", display->data);
    }
    printf("\n========================================\n");
}

size_t count()
{
    size_t count = 0;
    for (NODE *cnt = head; cnt != NULL;  cnt = cnt->next)
        ++count;

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

    if (pos == 0)
    {
        new->next = head;
        head = new;
    }
    else
    {
        NODE *t = head;// i = 0
        for (int i = 1; i < pos; ++i)
            t = t->next;
        new->next = t->next;
        t->next = new;

        if (new->next == NULL)
        {
            toe = new;
        }
    }
}

void deletebyposition()
{
    int pos;
    scanf("%d", &pos);

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
        NODE* t = head;// i = 0
        for (int i = 1; i < pos - 1; ++i)
            t = t->next;
        NODE* temp = t->next->next;
        free(t->next);
        t->next = temp;
        if (t->next == NULL)
            toe = t;
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

        if (t->next->data == value)
        {
            NODE* temp = t->next->next;
            free(t->next);
            t->next = temp;
            if (t->next == NULL)
                toe = t;
        }
        else
            printf("Number not found\n");
    }
}


size_t linear(int search)
{
    size_t pos = 0;
    for (NODE* check = head; check != NULL; check = check->next)
    {
        ++pos;
        if (check->data == search)
            return pos;//position that appears to user not index
    }
    return 0;//0 means element not found
}

int value_at_position(size_t n)
{
    n = (n <= count()) ? n : count(); //Overflow
    NODE* node = head;// i = 0
    for (int i = 1; i < n; ++i)
        node = node->next;

    return node->data;// Value stored at nth position from front
}

int value_at_end_position(int n)
{
    n = count() - n;
    n = (n >= 0) ? n : 0; //Overflow
    NODE* node = head;// i = 0
    for (int i = 1; i < n; ++i)
        node = node->next;

    return node->data;// Value stored at nth position from end
}

int mid()
{
    int n = count();
    n = n / 2;
    NODE* mid = head;
    for (int i = 0; i < n; ++i)
        mid = mid->next;

    return mid->data;// Value stored at mid position
}