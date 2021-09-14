#include <bits/stdc++.h>
using namespace std;

struct node
{
	int data {0};
	struct node* prev;
	struct node* next;
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

bool palindrome()
{
	NODE *i = head, *j = toe;
	while (i != j)
	{
		if (i->data != j->data)
			return false;
		else
		{
			i = i->next;
			j = j->prev;
		}
	}
	return true;
}

int main(void)
{
	cout << "List Size : ";
	int size {0};
	cin >> size;
	cout << "Enter Numbers\n";
	create(size);
	if (palindrome() == true)
	{
		cout << "palindrome";
	}
	else
		cout << "NOT palindrome";
	return 0;
}