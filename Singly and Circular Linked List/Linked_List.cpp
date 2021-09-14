#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data {0};
	struct node* next;
	node()
	{
		data = 0;
		next = NULL;
	}
	node(int value)
	{
		data = value;
		next = NULL;
	}
	node(int value, struct node* link)
	{
		data = value;
		next = link;
	}
}*head = NULL, *toe;

typedef struct node NODE;

NODE* create_node(NODE* previous) // Create single node at the end of previous
{
	NODE* new_node = new node;
	cin >> new_node->data;
	previous->next = new_node;
	return new_node;
}

void createlist(int size) // Create a list on 'n' elemnets at the end via looping
{
	while (size--)
	{
		NODE* new_node = new node;
		cin >> new_node->data;
		if (head == NULL)
		{
			head = new_node;
			toe = head;
		}
		else
		{
			toe->next = new_node;
			toe = new_node;
		}
	}
}

void create_list(int n) // Create a list on 'n' elemnets at the end via recurrsion
{
	if (n <= 0)
		return;
	else
	{
		NODE* new_node = new node;
		cin >> new_node->data;
		if (head == NULL)
		{
			head = new_node;
			toe = head;
		}
		else
		{
			toe->next = new_node;
			toe = new_node;
		}
	}
	create_list(n - 1);
}

void display() // Prints the List
{
	cout << "\n========================================\n";
	for (NODE* print = head; print != NULL; print = print->next)
	{
		cout << print->data << " ";
	}
	cout << "\n========================================\n";
}

int count() // Counts the Number of elements in the list
{
	size_t count {0};
	for (NODE* counting = head; counting != NULL; counting = counting->next)
	{
		++count;
	}
	return count;
}

void insert(int pos) // Add one new node in the list
{
	pos = (pos < count()) ? pos : count();// OverFlow
	pos = (pos > 0) ? pos : 0;// UnderFlow

	cout << "Value of new elemnet = ";
	NODE* new_node = new node;
	cin >> new_node->data;

	if (pos == 0)
	{
		new_node->next = head;
		head = new_node;
	}
	else
	{
		NODE* ptr = head;
		for (int i = 1; i < pos; ++i)
		{
			ptr = ptr->next;
		}
		new_node->next = ptr->next;
		ptr->next = new_node;
		if (new_node->next == NULL)
		{
			toe = new_node;
		}
	}
}

void delete_node(int pos) // Deletes a specific node
{
	pos = (pos < count()) ? pos : count();// OverFlow
	pos = (pos > 1) ? pos : 1;// UnderFlow

	if (pos == 1)
	{
		NODE* temp = head->next;
		free(head);
		head = temp;
	}
	else
	{
		NODE* ptr = head;
		for (int i = 1; i < pos - 1; ++i)
		{
			ptr = ptr->next;
		}
		NODE* temp = ptr->next->next;
		free(ptr->next);
		ptr->next = temp;
		if (temp == NULL)
		{
			toe = ptr;
		}
	}
}

bool delete_number(const int num) // Deletes a specific number
{
	if (head->data == num)
	{
		NODE* temp = head->next;
		free(head);
		head = temp;
		return true;
	}
	else
	{
		NODE* ptr = head;
		while (ptr->next->next != NULL)
		{
			if (ptr->next->data == num)
				break;
			else
				ptr = ptr->next;
		}
		if (ptr->next->data == num)
		{
			NODE* temp = ptr->next->next;
			free(ptr->next);
			ptr->next = temp;
			if (temp == NULL)
				toe = ptr;
			return true;
		}
	}
	return false; //false means number not found
}

int value_at_pos(int pos) // Value stored at postion 'pos' from beginning
{
	pos = (pos <= count()) ? pos : count();//Overflow
	NODE* node = head;// i = 0
	for (int i = 1; i < pos; ++i)
	{
		node = node->next;
	}
	return node->data;
}

int value_at_end_pos(int pos) // Value stored at postion 'pos' from end
{
	pos = count() - pos;
	pos = (pos >= 0) ? pos : 0; //Overflow
	NODE* node = head;// i = 0
	for (int i = 1; i < pos; ++i)
	{
		node = node->next;
	}
	return node->data;// Value stored at nth position from end
}

int mid() // Value stored in the middle
{
	int n = count();
	n = n / 2;
	NODE* mid = head;
	for (int i = 0; i < n; ++i)
	{
		mid = mid->next;
	}
	return mid->data;// Value stored at mid position
}

void rotate(int n) // Shifts the list 'times' towards left
{
	if (n == 0)
	{
		return;
	}
	else if (n == 1)
	{
		toe->next = head;
		NODE* temp = head->next;
		head->next = NULL;
		toe = head;
		head = temp;
	}
	else
	{
		NODE* ptr = head;
		for (int i = 1; i < n - 1; ++i)
		{
			ptr = ptr->next;
		}
		toe->next = head;
		head = ptr->next->next;
		ptr->next->next = NULL;
		toe = ptr->next;
	}
}

void rotate_left()
{
	NODE* temp = head->next;
	head->next = NULL;
	toe->next = head;
	toe = head;
	head = temp;
}

void rotate_right()
{
	NODE* temp = head;
	while (temp->next != toe)
	{
		temp = temp->next;
	}
	temp->next = NULL;
	toe->next = head;
	head = toe;
	toe = temp;
}

void swap_node(int pos1, int pos2) // InterChanges addresses of two nodes
{
	if (pos1 == 1)
	{
		NODE* replace = head;
		for (int i = 1; i < pos2 - 1; ++i)
		{
			replace = replace->next;
		}
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
		for (int i = 1; i < pos1 - 1; ++i)
		{
			replace1 = replace1->next;
		}
		NODE* replace2 = head;
		for (int i = 1; i < pos2 - 1; ++i)
		{
			replace2 = replace2->next;
		}
		NODE* temp = replace1->next;
		replace1->next = replace2->next;
		replace2->next = temp;
		temp = replace1->next->next;
		replace1->next->next = replace2->next->next;
		replace2->next->next = temp;
	}
}


bool swap_number(const int num1, const int num2) // InterChanges two nodes based on the basis of number stored
{
	if (num1 == head->data)
	{
		NODE* replace = head;
		while (replace->next != NULL && replace->next->data != num2)
		{
			replace = replace->next;
		}
		if (replace->next == NULL)
		{
			return false; // false means Number not found
		}
		else
		{
			NODE* temp = replace->next->next;
			replace->next->next = head->next;
			head->next = temp;
			temp = replace->next;
			replace->next = head;
			head = temp;
			return true;
		}
	}
	else if (num2 == head->data)
	{
		NODE* replace = head;
		while (replace->next != NULL && replace->next->data != num1)
		{
			replace = replace->next;
		}
		if (replace->next == NULL)
		{
			return false;
		}
		else
		{
			NODE* temp = replace->next->next;
			replace->next->next = head->next;
			head->next = temp;
			temp = replace->next;
			replace->next = head;
			head = temp;
			return true;
		}
	}
	else
	{
		NODE* replace1 = head;
		while (replace1->next != NULL && replace1->next->data != num1)
		{
			replace1 = replace1->next;
		}
		if (replace1->next == NULL)
		{
			return false;
		}
		else
		{
			NODE* replace2 = head;
			while (replace2->next != NULL && replace2->next->data != num2)
			{
				replace2 = replace2->next;
			}
			if (replace2->next == NULL)
			{
				return false;
			}
			else if (replace1->next->data == num1 && replace2->next->data == num2)
			{
				NODE* temp = replace1->next;
				replace1->next = replace2->next;
				replace2->next = temp;
				temp = replace1->next->next;
				replace1->next->next = replace2->next->next;
				replace2->next->next = temp;
				return true;
			}
		}
	}
	return false;
}

NODE* frequency() // Creates a list which stores the frequency of list
{
	NODE *frequency = NULL, *create;

	create = frequency;

	NODE* i = head;
	while (i != NULL)
	{
		NODE* count = (NODE*)malloc(sizeof(NODE));
		count->data = 1;
		count->next = NULL;
		create->next = count;
		create = count;
		i = i->next;
	}

	NODE* count = frequency;
	i = head;
	while (i != NULL)
	{
		NODE* check = count->next;
		NODE* j = i->next;
		while (j != NULL)
		{
			if (i->data == j->data)
			{
				if (check->data != 0 && i->data != 0)
				{
					i->data += 1;
					check->data = 0;
				}
			}
			j = j->next;
			check = check->next;
		}
		i = i->next;
		count = count->next;
	}
	return frequency;
}

bool check_loop() //  Checks whether the list is circular or not
{
	NODE* check = head;
	while (check != NULL)
	{
		for (NODE* i = check->next; i != NULL; i = i->next)
		{
			if (i == check)
			{
				return true; // true means loop exists
			}
		}
	}
	return false;
}

void make_circular() // Convets singularily connect Linked List into circular
{
	NODE *circular = head;
	while (circular->next != NULL)
	{
		circular = circular->next;
	}
	circular->next = head;
}

/*  SEARCH */

int linear(const int search)
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

int bi_search(const int value) // works only for sorted array >> 2x faster than linear
{
	if (toe->data == value)// checking last node
	{
		return count();
	}
	else if (((toe == head || head->next == NULL) && head->data == value) || head->data == value)
	{
		return 1;
	}
	else
	{
		int pos = 0;
		for (NODE* check = head; check != NULL && check->next != NULL; check = check->next->next)
		{
			if (check->next->data < value)
			{
				pos += 2;
			}
			else if (check->data == value)
			{
				++pos;
				return pos;
			}
			else if (check->next->data == value)
			{
				pos += 2;
				return pos;
			}
			else
				return 0;// 0 means number not found
		}
	}
	return 0;
}

int tri_search(); // Stil under progress

/* SORT */

bool check_sort()// Checks whether list is sorted or not
{
	NODE* check = head;
	while (check != NULL)
	{
		if (check->data > check->next->data)
		{
			return false;
		}
		check = check->next;
	}
	return true;
}

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

void bubble_circular()
{
	NODE* i = head;
	do {
		NODE* j = head;
		do {
			if (j->data > j->next->data)
			{
				int temp;
				temp = j->data;
				j->data = j->next->data;
				j->next->data = temp;
			}
			j = j->next;

		} while ( j->next != head);

		i = i->next;

	} while ( i != head);
}

int tri_search(const int value)
{
	if (toe->data == value)// checking last node
		return count();
	else
	{
		int pos = 0;
		NODE* check;
		for (check = head; check != NULL && check->next != NULL && check->next->next != NULL; check = check->next->next->next)
		{
			if (check->next->next->data < value || check->next == NULL || check->next->next == NULL)
				pos += 3;
			else
			{
				if (check->data == value)
				{
					++pos;
					return pos;
				}
				else
				{
					if (check->next->data == value)
					{
						pos += 2;
						return pos;
					}
					else
					{
						if (check->next->next->data == value)
						{
							pos += 3;
							return pos;
						}
						else
							return 0;// 0 means number not found
					}
				}
			}
		}
		if (check->next->data == value)
			return count() - 1;
		else
			return 0;
	}
	return 0;
}