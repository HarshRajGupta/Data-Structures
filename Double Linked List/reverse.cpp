#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data {0};
	struct node* prev {NULL};
	struct node* next {NULL};
}*head = NULL, *toe;

typedef struct node NODE;

void create(int n)// Creates or Extends list by 'n'
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

	for (int i = 0; i < n; ++i)
	{
		NODE* node = (NODE*)malloc(sizeof(NODE));
		cin >> node->data;
		node->prev = toe;
		node->next = NULL;
		toe->next = node;
		toe = node;
	}
}

void display()// Print the Current list
{
	cout << "\n========================================\n";

	for (NODE* print = head; print != NULL; print = print->next)
	{
		cout << print->data << " ";
	}

	cout << "\n========================================\n";
}

void display_end()// Prints list in reverse order
{
	cout << "\n========================================\n";

	for (NODE* print = toe; print != NULL; print = print->prev)
	{
		cout << print->data << " ";
	}

	cout << "\n========================================\n";
}

void reverse()
{
	NODE *previous = NULL, *current = head;
	while (current != NULL)
	{
		NODE* current_next = current->next;
		current->next = previous;
		current->prev = current_next;
		previous = current;
		current = current_next;
	}
	toe = head;
	head = previous;
}

int main(void)
{
	cout << "List Size : ";
	int size {0};
	cin >> size;
	cout << "Enter Numbers" << endl;
	create(size);
	cout << "\nOrignal List";
	display();
	cout << "\nReversed List";
	reverse();
	display();
	display_end();
	return 0;
}