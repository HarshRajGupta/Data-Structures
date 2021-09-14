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

int count()
{
	int count {0};
	for(NODE* i=head; i!=NULL; i=i->next)
		++count;
	return count;
}

void display()
{
	cout << "\n========================================\n";

	for(NODE* print=head; print!=NULL; print=print->next)
		cout << print->data << " ";

	cout << "\n========================================\n";
}

void display_end()
{
	cout << "\n========================================\n";
	for(NODE* print=toe; print!=NULL; print=print->prev)
		cout << print->data << " ";
	cout << "\n========================================\n";
}

void swap_node(int pos1, int pos2)
{
	if(pos1 == 1)
	{
		NODE* replace = head;
		for(int i=1; i<pos2; ++i)
			replace = replace->next;
		
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
	else
	{
		int n = count();
		if (pos2 == n)
		{
			NODE* replace = head;
			for(int i=1; i<pos1; ++i)
			    replace = replace->next;

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
		else
		{
			if (pos1 > n || pos2 > n)
				return;
			else
			{
			    NODE* replace1 = head;
			    for(int i=1; i<pos1; ++i)
				    replace1 = replace1->next;

			    NODE* replace2 = head;
			    for(int i=1; i<pos2; ++i)
				    replace2 = replace2->next;

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
	}
}

int main(void)
{
	cout << "List Size : ";
	int size {0};
	cin >> size;
	cout << "Enter Numbers" << endl;
	create(size);
	display();
	cout << "Enter nodes to interchange : ";
	int pos1, pos2;
	cin >> pos1 >> pos2;
	swap_node(pos1, pos2);
	display_end();
	return 0;
}