#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node* prev;
	struct node* next;
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

int count()// Counts total number of elements in the list
{
	int count {0};
	for (NODE* i = head; i != NULL; i = i->next)
	{
		++count;
	}
	return count;
}

void insert(int pos)// Inserts an extra node in the list
{
	int n = count();
	NODE* new_node = (NODE*)malloc(sizeof(NODE));
	new_node->prev = NULL;
	new_node->next = NULL;
	cin >> new_node->data;
	if (n == 0)
	{
		pos = 0;
	}
	if (pos <= 0)
	{
		new_node->next = head;
		if (head != NULL)
		{
			head->prev = new_node;
		}
		head = new_node;
	}
	else if (pos >= n)
	{
		new_node->prev = toe;
		toe->next = new_node;
		toe = new_node;
	}
	else if (pos < n / 2)
	{
		NODE* ptr = head;
		for (int i = 1; i < pos; ++i)
		{
			ptr = ptr->next;
		}
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
		{
			ptr = ptr->prev;
		}
		new_node->prev = ptr->prev;
		new_node->next = ptr;
		ptr->prev->next = new_node;
		ptr->prev = new_node;
	}
}

void delete_node(int pos)// Delete by Position
{
	int n = count();
	if ( n == 0)
	{
		return;
	}
	else if (pos < 0 || pos > n)
	{
		cout << "Invalid Location";
		return;
	}
	else if (pos == 1 || pos == 0)
	{
		NODE* temp = head->next;
		head->next->prev = NULL;
		head->next = NULL;
		free(head);
		head = NULL;
		head = temp;
	}
	else if (pos == n)
	{
		NODE* temp = toe->prev;
		toe->prev->next = NULL;
		free (toe);
		toe = NULL;
		toe = temp;
	}
	else if (pos < n / 2)
	{
		NODE* ptr = head;
		for (int i = 1; i < pos; ++i)
		{
			ptr = ptr->next;
		}
		ptr->prev->next = ptr->next;
		ptr->next->prev = ptr->prev;
		free (ptr);
		ptr = NULL;
	}
	else
	{
		NODE* ptr = toe;
		pos = n - pos;
		for (int i = 1; i <= pos; ++i)
		{
			ptr = ptr->prev;
		}
		ptr->next->prev = ptr->prev;
		ptr->prev->next = ptr->next;
		free (ptr);
		ptr = NULL;
	}
}

bool delete_number(int num)// Delete by Value
{
	if (head != NULL && head->data == num)
	{
		NODE* temp = head->next;
		if (head->next != NULL)
		{
			head->next->prev = NULL;
		}
		free (head);
		head = temp;
		return true;
	}
	else if (head != NULL && toe->data == num)
	{
		NODE* temp = toe->prev;
		toe->prev->next = NULL;
		free (toe);
		toe = temp;
		return true;
	}
	else if (head != NULL)
	{
		NODE* ptr = head;
		while (ptr->data != num && ptr != toe)
		{
			ptr = ptr->next;
		}
		if (ptr != NULL && ptr->data == num)
		{
			ptr->prev->next = ptr->next;
			ptr->next->prev = ptr->prev;
			free (ptr);
			return true;
		}
	}
	return false;// false means number not found
}

void rotate_right()// Right Shift
{
	if (head != NULL && head != toe)
	{
		head->prev = toe;
		toe->next = head;
		toe->prev->next = NULL;
		NODE* temp = toe->prev;
		toe->prev = NULL;
		head = toe;
		toe = temp;
	}
}

void rotate_left()// Left Shift
{
	if (head != NULL && head != toe)
	{
		head->prev = toe;
		toe->next = head;
		head->next->prev = NULL;
		NODE* temp = head->next;
		head->next = NULL;
		toe = head;
		head = temp;
	}
}

bool palindrome()// Is list symetrical about the mid?
{
	NODE *i = head, *j = toe;
	while (i != j && i != NULL && j != NULL)
	{
		if (i->data != j->data)
		{
			return false;
		}
		else
		{
			i = i->next;
			j = j->prev;
		}
	}
	return true;
}

void swap_node(int pos1, int pos2)// Interchanges Address of Two Nodes
{
	int n = count();

	if (pos1 == 1)//
	{
		NODE* replace = head;
		for (int i = 1; i < pos2; ++i)
		{
			replace = replace->next;
		}
		replace->prev->next = head;
		replace->next->prev = head;
		head->next->prev = replace;
		NODE* temp = head->next;
		head->prev = replace->prev;
		head->next = replace->next;
		replace->prev = NULL;
		replace->next = temp;
		head = replace;
		return;
	}
	else if (pos2 == n)
	{
		NODE* replace = head;
		for (int i = 1; i < pos1; ++i)
		{
			replace = replace->next;
		}

		replace->prev->next = toe;
		replace->next->prev = toe;
		toe->prev->next = replace;
		NODE* temp = toe->prev;
		toe->prev = replace->prev;
		toe->next = replace->next;
		replace->prev = temp;
		replace->next = NULL;
		toe = replace;
		return;
	}
	else if (pos1 > n || pos2 > n || pos1 < 0 || pos2 < 0)
	{
		return;
	}
	else
	{
		NODE* replace1 = head;
		for (int i = 1; i < pos1; ++i)
		{
			replace1 = replace1->next;
		}
		NODE* replace2 = head;
		for (int i = 1; i < pos2; ++i)
		{
			replace2 = replace2->next;
		}
		replace1->prev->next = replace2;
		replace1->next->prev = replace2;
		replace2->prev->next = replace1;
		replace2->next->prev = replace1;
		NODE* temp_prev = replace1->prev;
		NODE* temp_next = replace1->next;
		replace1->prev = replace2->prev;
		replace1->next = replace2->next;
		replace2->prev = temp_prev;
		replace2->next = temp_next;
	}
}

// SEARCH

int linear(int search)
{
	int pos = 0;
	NODE* identify = head;
	while (identify != NULL)
	{
		++pos;
		if (identify->data == search)
		{
			return pos;
		}
		identify = identify->next;
	}
	return 0;// 0 means number not found
}

// SORT

void bubble()
{
	for (NODE* i = head; i != NULL; i = i->next)
	{
		for (NODE* j = head; j->next != NULL; j = j->next)
		{
			if (j->data > j->next->data)
			{
				int temp;
				temp = j->data;
				j->data = j->next->data;
				j->next->data = temp;
			}
		}
	}
}