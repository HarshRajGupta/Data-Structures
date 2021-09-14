#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX {100};

bool push(int* Arr, int &top)
{
    if  (top < MAX) 
    {
        int n;
        scanf("%d", &n);
        ++top;
        *(Arr + top) = n;
        return true;
    }
    else
        return false;
}

bool pop(int* Arr, int &top)
{
    if (top >= 0)
    {
        top--;
        return true;
    }
    else
        return false;
}

void display(int Arr[], int &top)
{
    if (top >= 0)
    {
       
        for (int i = 0; i <= top; ++i)
        {
            printf("%d ", Arr[i]);
        }
       
    }
    else
        printf("Stack is empty\n");
}

int main(void)
{
    int ch = 0;
    int Arr[MAX] {0};
    int top { -1};
    while (ch != 4)
    {
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter your Choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nData to Push : ");
            if (push(Arr, top) == true)
            {
                printf("Done Succesfully\n\n");
            }
            else
            {
                printf("Stack is full\n\n");
            }
            break;

        case 2:
            if (pop(Arr, top) == true)
            {
                printf("\nDone Succesfully\n\n");
            }
            else
            {
                printf("\nStack is empty\n\n");
            }
            break;

        case 3:
            display(Arr, top);
            break;

        case 4:
            printf("Thank You\n");
            break;

        default:
            printf("Wronng Choice\nPlease Select the correct one\n\n");
            break;
        }
    }
    return 0;
}