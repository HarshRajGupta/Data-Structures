#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	struct node* next;
}*head = NULL, *toe;

typedef struct node NODE;

NODE* create_node(NODE* previous, int value);

void create(int n);

void create_list(int n);

void display();
// Prints the List

int count();
// Counts the Number of elements in the list

void insert(int pos);
// Add one new node in the list

void delete_node(int pos);
// Deletes a specific node

bool delete_number(int num);
// Deletes a specific number

int value_at_pos(int pos);
// Value stored at postion 'pos' from beginning

int value_at_end_pos(int pos);
// Value stored at postion 'pos' from end

int mid();
// Value stored in the middle

void rotate_n_times(int times);
// Shifts the list 'times' towards left

void rotate_right();

void rotate_left();

void swap_node(int pos1, int pos2);
// InterChanges addresses of two nodes

bool swap_number(int num1, int num2);
// InterChanges two nodes based on the basis of number stored

NODE* frequency();
// Creates a list which stores the frequency of list

bool check_loop();
//  Checks whether the list is circular or not

void make_circular();
// Convets singularily connect Linked List into circular

/*  SEARCH */

int linear(int);

int bi_search();

int tri_search();

/* SORT */

bool check_sort();
// Checks whether list is sorted or not

void bubble();

void bubble_circular();

/* int main(int argc, char const *argv[])
{
	 code 
	return 0;
} */

NODE* create_node(NODE* previous, int value)// Create single node at the end of previous
{
	NODE* node = (NODE*)malloc(sizeof(NODE));
	node->data = value;
	node->next = NULL;
	previous->next = node;
	return node;
}

void create(int n)// Creates or Extends list by 'n' at the end via iteration
{
	if (head == NULL)
	{
		head = (NODE*)malloc(sizeof(NODE));
		cin >> head->data;
		head->next = NULL;
		toe = head;
		--n;
	}

	for (int i = 0; i < n; ++i)
	{
		NODE* node = (NODE*)malloc(sizeof(NODE));
		cin >> node->data;
		node->next = NULL;
		toe->next = node;
		toe = node;
	}
}

void create_list(int n)// Creates or Extends list by 'n' at the end via recurrsion
{
	if (n <= 0)
		return;
	else
	{
		NODE* node = (NODE*)malloc(sizeof(NODE));
		cin >> node->data;
		node->next = NULL;

		if (head == NULL)
		{
			head = node;
			toe = node;
		}
		else
		{
			toe->next = node;
			toe = node;
		}
	}
	create_list(n - 1);
}

void display()
{
	cout << "\n++++----++++----++++----++++----++++\n";

	for (NODE* print = head; print != NULL; print = print->next)
	{
		cout << print->data << " ";
	}

	cout << "\n++++----++++----++++----++++----++++\n";
}

int count()
{
	size_t count {0};

	for (NODE* counting = head; counting != NULL; counting = counting->next)
	{
		++count;
	}

	return count;
}

void insert(int pos)
{
	pos = (pos < count()) ? pos : count();// OverFlow
	pos = (pos > 0) ? pos : 0;// UnderFlow

	cout << "Value of new elemnet = ";
	NODE* new_node = (NODE*)malloc(sizeof(NODE));
	cin >> new_node->data;
	new_node->next = NULL;

	if (pos == 0)
	{
		new_node->next = head;
		head = new_node;
	}
	else
	{
		NODE* ptr = head;
		for (int i = 1; i < pos; ++i)
			ptr = ptr->next;

		new_node->next = ptr->next;
		ptr->next = new_node;

		if (new_node->next == NULL)
			toe = new_node;
	}
}

void delete_node(int pos)
{
	pos = (pos < count()) ? pos : count();// OverFlow

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
			ptr = ptr->next;

		NODE* temp = ptr->next->next;
		free(ptr->next);
		ptr->next = temp;

		if (temp == NULL)
			toe = ptr;
	}
}

bool delete_number(int num)
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
		else
			return false;//false means number not found
	}
	return false;
}

int value_at_pos(int n)
{
	n = (n <= count()) ? n : count();//Overflow
	NODE* node = head;// i = 0
	for (int i = 1; i < n; ++i)
		node = node->next;

	return node->data;// Value stored at nth position from front
}

int value_at_end_pos(int n)
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

void rotate_n_times(int n)
{
	if (n == 0)
		return;

	else if (n == 1)
	{

		NODE* temp = head->next;
		toe->next = head;
		head->next = NULL;
		toe = head;
		head = temp;
	}
	else
	{
		NODE* ptr = head;
		for (int i = 1; i < n - 1; ++i)
			ptr = ptr->next;

		toe->next = head;
		NODE* tag = head;
		tag = ptr->next->next;
		ptr->next->next = NULL;
		toe = ptr->next;
		head = tag;
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

void swap_node(int pos1, int pos2)
{
	if (pos1 == 1)
	{
		NODE* replace = head;
		for (int i = 1; i < pos2 - 1; ++i)
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
		for (int i = 1; i < pos1 - 1; ++i)
			replace1 = replace1->next;

		NODE* replace2 = head;
		for (int i = 1; i < pos2 - 1; ++i)
			replace2 = replace2->next;

		NODE* temp = replace1->next;
		replace1->next = replace2->next;
		replace2->next = temp;
		temp = replace1->next->next;
		replace1->next->next = replace2->next->next;
		replace2->next->next = temp;
	}
}

bool swap_number(const int num1, const int num2)
{
	if (head->data == num1)
	{
		NODE* replace = head;
		for (int i = 1; i < num2 - 1; ++i)
			replace = replace->next;

		NODE* temp = replace->next->next;
		replace->next->next = head->next;
		head->next = temp;
		temp = replace->next;
		replace->next = head;
		head = temp;
		return true;
	}
	else
	{
		NODE* replace1 = head;
		while (replace1->next->data != num1 && replace1->next != NULL)
			replace1 = replace1->next;

		NODE* replace2 = head;
		while (replace2->next->data != num2 && replace2->next != NULL)
			replace2 = replace2->next;

		if (replace1->next->data == num1 && replace2->next->data == num2)
		{
			NODE* temp = replace1->next;
			replace1->next = replace2->next;
			replace2->next = temp;
			temp = replace1->next->next;
			replace1->next->next = replace2->next->next;
			replace2->next->next = temp;
			return true;
		}
		else
			return false;
	}
	return false;
}

NODE* frequency()
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

bool check_loop()
{
	NODE* check = head;
	while (check != NULL)
	{
		for (NODE* i = check->next; i != NULL; i = i->next)
		{
			if (i == check)
			{
				return true;
			}
		}
	}
	return false;
}

void make_circular()
{
	NODE *circular = head;
	while (circular->next != NULL)
	{
		circular = circular->next;
	}
	circular->next = head;
}

int linear(int search)
{
	int pos = 0;
	NODE* identify = head;
	while (identify != NULL)
	{
		++pos;

		if (identify->data == search)
			return pos;

		identify = identify->next;
	}
	return 0;// 0 means number not found
}

int bi_search(int value)
{
	if (toe->data == value)// checking last node
		return count();
	else
	{
		int pos = 0;
		for (NODE* check = head; check != NULL && check->next != NULL; check = check->next->next)
		{
			if (check->next->data < value || check->next == NULL)
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

int tri_search(int value)
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
			else if (check->next->next->data == value)
			{
				pos += 3;
				return pos;
			}
			else
				return 0;// 0 means number not found

		}
		if (check->next->data == value)
		{
			return count() - 1;
		}
	}
	return 0;
}

bool check_sort()
{
	NODE* check = head;
	while (check != NULL)
	{
		if (check->data > check->next->data)
			return false;
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
	do 
	{
		NODE* j = head;
		do 
		{
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