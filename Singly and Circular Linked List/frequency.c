#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL, *ptr;

typedef struct node NODE;

//NODE* freq = NULL, *fend;

void createList(int n);

void display();

NODE* frequency();

void swap_node(int pos1, int pos2)
{
    if (pos1 == 1)
    {
        NODE* replace = head;
        for(int i=1; i<pos2-1; ++i)
            replace = replace->next;

        NODE* temp = replace->next->next;
        replace->next->next = head->next;
        head->next = temp;
        temp = replace->next;
        replace->next = head;
        head = temp;
    }
    else
    {
        NODE* replace1 = head;
        for(int i=1; i<pos1-1; ++i)
            replace1 = replace1->next;

        NODE* replace2 = head;
        for(int i=1; i<pos2-1; ++i)
            replace2 = replace2->next;

        NODE* temp = replace1->next;
        replace1->next = replace2->next;
        replace2->next = temp;
        temp = replace1->next->next;
        replace1->next->next = replace2->next->next;
        replace2->next->next = temp;
    }
}

void swap_number(const int num1,const int num2)
{
    if (head->data == num1)
    {
        NODE* replace = head;
        for(int i=1; i<num2-1; ++i)
            replace = replace->next;

        NODE* temp = replace->next->next;
        replace->next->next = head->next;
        head->next = temp;
        temp = replace->next;
        replace->next = head;
        head = temp;
        return;
    }
    else
    {
        NODE* replace1 = head;
        while(replace1->next->data != num1 && replace1->next!=NULL)
            replace1 = replace1->next;

        NODE* replace2 = head;
        while(replace2->next->data != num2 && replace2->next!=NULL)
            replace2 = replace2->next;

        if(replace1->next->data==num1 && replace2->next->data==num2)
        {
            NODE* temp = replace1->next;
            replace1->next = replace2->next;
            replace2->next = temp;
            temp = replace1->next->next;
            replace1->next->next = replace2->next->next;
            replace2->next->next = temp;
            return;
        }
        else
        {
            printf("Invalid input\n");
            return;
        }
    }
}

int main(void)
{
	printf("List Size : ");
	int n;
	scanf("%d", &n);
	printf("Enter %d Numbers\n", n);
	createList(n);
    printf("Enter Numbers to swap\n");
    int n1, n2;
    scanf("%d%d", &n1, &n2);
    swap_number(n1, n2);
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
    printf("\n====================================\n");

    //NODE* print = freq;
    for ( NODE *display=head; display!=NULL; display=display->next)
    {
       // if (print->data != 0)
            printf("%d ",display->data);
       // print = print->next;
    }
    printf("\n====================================\n"); 

}


NODE* frequency()
{
    NODE* freq = (NODE*)malloc(sizeof(NODE));
    freq->data = 1;
    freq->next = NULL;
    NODE* fend = freq;

    for(NODE* i=head->next; i!=NULL; i=i->next)
    {
        NODE* node = (NODE*)malloc(sizeof(NODE));
        node->data = 1;
        node->next = NULL;
        fend->next = node;
        fend = node;
    }

    NODE *count = freq;
    for(NODE* i=head; i!=NULL; i=i->next)
    {
        NODE* check = count->next;
        for(NODE* j=i->next; j!=NULL; j=j->next)
        {
            if (i->data == j->data)
            {
                if(check->data != 0 && count->data !=0)
                {
                    count->data+=1;
                    check->data = 0;
                }
            }
            check=check->next;
        }
        count = count->next;
    }
    return freq;
}