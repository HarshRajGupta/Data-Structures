#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
	int data {0};
	struct node* prev {NULL};
	struct node* next {NULL};
}*head=NULL, *toe;

typedef struct node NODE;

void create(int n)
{
	if (head == NULL)
	{
		head = (NODE*)malloc(sizeof(NODE));
		cin >> head->data;
		head->prev = NULL;
		head->next = NULL;
		toe = head;
		--n;
	}

	for(int i=0; i<n; ++i)
	{
		NODE* node = (NODE*)malloc(sizeof(NODE));
		cin >> node->data;
		node->prev = toe;
		node->next = NULL;
		toe->next = node;
		toe = node;
	}
}

void display()
{
	cout << "\n========================================\n";

	for(NODE* print=head; print!=NULL; print=print->next)
	{
		cout << print->data << " ";
	}

	cout << "\n========================================\n";
}

void display_end()
{
	cout << "\n========================================\n";

	for(NODE* print=toe; print!=NULL; print=print->prev)
	{
		cout << print->data << " ";
	}
	
	cout << "\n========================================\n";
}

int main(void)
{
	cout << "List Size : ";
	int size {0};
	cin >> size;
	cout << "Enter Numbers" << endl;
	create(size);
	display();
	display_end();
	return 0;
}