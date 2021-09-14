#include <iostream>
using namespace std;

struct node
{
	long int data;
	struct node* next;
}*head=NULL, *tag, *toe;

typedef struct node NODE;

void createList(int n);

void display();

void rotate(int);

int main(void)
{
	cout << "List Size : ";
	int size {0};
	cin >> size;
	cout << "Enter Numbers" << endl;
	createList(size);
	display();
	cout << "No. of rotations : ";
	int rotation {0};
	cin >> rotation;
	rotation = rotation%size;
	rotate(rotation);
	display();

	return 0;
}

void createList(int n)
{
    if(n <= 0)
        return;

    else
    {
        NODE* node = (NODE*)malloc(sizeof(NODE));
        cin >> node->data;
        node->next = NULL;

        if(head == NULL)
        {
            head = node;//List started
            toe = head;//end will connect nodes
            tag = head;
        }
        else
        {
            toe->next = node;//end connected the new node
            toe = node;//end again becomes the last node
        }   
        createList(n-1);//Recursion Call
    }
}

void display()
{
    cout << "\n========================================\n";
    for ( NODE* display=tag; display!=NULL; display=display->next)
    {
        cout << display->data << " ";
    }
    cout << "\n========================================" << endl;
}

void rotate(int n)
{
	if (n == 0)
		return;
	else
	{
		if (n == 1)
		{
			tag = head->next;
			toe->next = head;
			head->next = NULL;
			toe = head;
		}
		else
		{
			NODE* ptr = tag;
			for(int i=1; i<n-1; ++i)
				ptr = ptr->next;

			toe->next = tag;
			tag = ptr->next->next;
			ptr->next->next = NULL;
			toe = ptr->next;
		}
	}
}