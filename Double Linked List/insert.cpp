#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
	int data {0};
	struct node* prev {NULL};
	struct node* next {NULL};
}*head = NULL, *toe;

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

int count()
{
	int count {0};
	for (NODE* i = head; i != NULL; i = i->next)
		++count;
	return count;
}

void insert_node(int pos)
{
	NODE* new_node = (NODE*)malloc(sizeof(NODE));
	new_node->prev = NULL;
	new_node->next = NULL;
	cin >> new_node->data;

	if (pos <= 0)
	{
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
	}
	else
	{
		if (pos < count())
		{
			NODE* ptr = head;
			for (int i = 1; i < pos; ++i)
				ptr = ptr->next;

			new_node->prev = ptr;
			new_node->next = ptr->next;
			ptr->next->prev = new_node;
			ptr->next = new_node;
		}
		else// fails only for 'NULL->prev = new_node'
		{
			new_node->prev = toe;
			toe->next = new_node;
			toe = new_node;
		}
	}
}

void insert(int pos)// more time efficient
{
	int n = count();
	NODE* new_node = (NODE*)malloc(sizeof(NODE));
	new_node->prev = NULL;
	new_node->next = NULL;
	cin >> new_node->data;

	if (pos <= 0)
	{
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
	}
	else
	{
		if (pos >= n)
		{
			new_node->prev = toe;
			toe->next = new_node;
			toe = new_node;
		}
		else
		{
			if (pos < n / 2)
			{
				NODE* ptr = head;
				for (int i = 1; i < pos; ++i)
					ptr = ptr->next;

				new_node->prev = ptr;
				new_node->next = ptr->next;
				ptr->next->prev = new_node;
				ptr->next = new_node;
			}
			else
			{
				NODE* ptr = toe;
				pos = n - pos;
				for (int i = 1; i < pos; ++i)
					ptr = ptr->prev;

				new_node->prev = ptr->prev;
				new_node->next = ptr;
				ptr->prev->next = new_node;
				ptr->prev = new_node;
			}
		}
	}
}

void display()
{
	cout << "\n========================================\n";

	for (NODE* print = head; print != NULL; print = print->next)
		cout << print->data << " ";

	cout << "\n========================================\n";
}

void display_end()
{
	cout << "\n========================================\n";
	for (NODE* print = toe; print != NULL; print = print->prev)
		cout << print->data << " ";
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
	cout << "Position to insert : ";
	int pos;
	cin >> pos;
	cout << "Number = ";
	insert(pos);
	display();
	cout << "Position to insert : ";
	cin >> pos;
	cout << "Number = ";
	insert_node(pos);
	display_end();
	return 0;
}