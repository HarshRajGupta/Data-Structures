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

int count()
{
	int count {0};

	for (NODE* i = head; i != NULL; i = i->next)
	{
		++count;
	}
	
	return count;
}

void delete_node(int pos)
{
	int n = count();

	if (pos < 0 || pos > n)
	{
		cout << "Invalid Location";
		return;
	}
	else
	{
		if (pos == 1 || pos == 0)
		{
			NODE* temp = head->next;
			head->next->prev = NULL;
			head->next = NULL;
			free(head);
			head = temp;
		}
		else
		{
			if (pos == n)
			{
				NODE* temp = toe->prev;
				toe->prev->next = NULL;
				free (toe);
				toe = temp;
			}
			else
			{
				if (pos < n / 2)
				{
					NODE* ptr = head;
					for (int i = 1; i < pos; ++i)
						ptr = ptr->next;
					ptr->prev->next = ptr->next;
					ptr->next->prev = ptr->prev;
					free (ptr);
				}
				else
				{
					NODE* ptr = toe;
					pos = n - pos;
					for (int i = 1; i <= pos; ++i)
						ptr = ptr->prev;
					ptr->next->prev = ptr->prev;
					ptr->prev->next = ptr->next;
					free (ptr);
				}
			}

		}
	}
}

bool delete_number(int num)
{
	if (head->data == num)
	{
		NODE* temp = head->next;
		head->next->prev = NULL;
		free (head);
		head = temp;
		return true;
	}
	else
	{
		if (toe->data == num)
		{
			NODE* temp = toe->prev;
			toe->prev->next = NULL;
			free (toe);
			toe = temp;
			return true;
		}
		else
		{
			NODE* ptr = head;
			while (ptr->data != num && ptr != NULL)
				ptr = ptr->next;
			if (ptr != NULL)
			{
				ptr->prev->next = ptr->next;
				ptr->next->prev = ptr->prev;
				free (ptr);
				return true;
			}
		}
	}
	return false;
}

int main(void)
{
	cout << "List Size : ";
	int size {0};
	cin >> size;
	cout << "Enter Numbers" << endl;
	create(size);
	display();

	cout << "Position to delete : ";
	int pos;
	cin >> pos;
	delete_node(pos);
	display();

	cout << "Number to delete : ";
	cin >> pos;
	delete_number(pos);
	display_end();
	return 0;
}