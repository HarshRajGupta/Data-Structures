#include <iostream>
#include <cstdlib>
using namespace std;

struct node
{
	int data {0};
	struct node* next;
}*head = NULL, *toe;

typedef struct node NODE;

void createList(int n);
// Create a list on 'n' elemnets at the end via Looping

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

void rotate_right();

void rotate_left();

/* SEARCH */

int linear(int);

/*  SORT  */

void bubble();

int main()
{
	int ch {0};
	while (ch != 9)
	{
		int n {0};
		cout << "1.Create\n2.Insert\n3.Delete\n4.Count\n5.More" << endl;
		cout << "Enter your choice : ";
		cin >> ch;

		switch (ch)
		{
		case 1: cout << "\nList Size : ";
		        cin >> n;
		        cout << "Enter " << n << " numbers" << endl;
		        createList(n);
		        break;

		case 2: cout << "1.At begining\n2.At end\n3.Custom" << endl;
		        cin >> n;
		        if(n == 1)
		        {
		        	insert(0);
		        }
		        else if (n == 2)
		        {
		        	insert(count());
		        }
		        else
		        {
		        	cout << "Position : ";
		        	cin >> n;
		        	insert(n);
		        }
		        break;

		case 3: cout << "1.Delete Node\n2.Delete Number" << endl;
		        cin >> n;
		        if (n==1)
		        {
		        	cout << "Position of the Node : ";
		        	cin >> n;
		        	delete_node(n);
		        }
		        else
		        {
		        	cout << "Enter number : ";
		        	cin >> n;
		        	if (delete_number(n) == true)
		        	{
		        		cout << "Deleted Sucessfully" << endl;
		        	}
		        	else
		        	{
		        		cout << "Number not Found" << endl;
		        	}
		        }
		        break;

		case 4: cout << "List has " << count() << " elements" << endl;
		        break;

		case 5: cout << "1.Search\n2.See Value\n3.Sort\n4.Rotate\n5.Occurence" << endl;
		        cout << "Enter your choice : ";
		        cin >> ch;

		        switch(ch)
		        {
		        case 1: cout << "Enter the number : ";
		                cin >> n;
		                int pqr;
		                pqr = linear(n);
		                if (pqr != 0)
		                {
		                	cout << n << "found at Position " << pqr << endl;
		                }
		                else
		                {
		                	cout << "Number not found" << endl;
		                }
		                break;

		        case 2: cout << "1.From begining\n2.From end" << endl;
		                cin >> n;
		                if (n == 1)
		                {
		                	cout << "Enter Position : ";
		                	cin >> n;
		                	cout << "\n" << value_at_pos(n) << "Value stored at position " << n << endl;
		                }
		                else if (n == 2)
		                {
		                	cout << "Enter Position : ";
		                	cin >> n;
		                	cout << "\n" << value_at_end_pos(n) << "Value stored at position " << n << endl;
		                }
		                break;

		        case 3: bubble();
		                break;

		        case 4: cout << "1.Right\n2.Left\n";
		                cin >> n;
		                if (n == 1)
		                {
		                	rotate_right();
		                }
		                else if (n == 2)
		                {
		                	rotate_left();
		                }
		                break;

		        default:cout << "Wrong Choice" << endl;
		                break;
		        }
		        break;

		default:cout << "Wrong Choice" << endl;
		        break;
		}

		cout << "\n0.Continue\n1.See List\n9.Exit\n";
		cin >> ch;
		if (ch == 1)
		{
			display();
			cout << "\n0.Continue\n9.Exit\n";
			cin >> ch;
		}
		if (ch == 9)
		{
			cout << "THANK YOU" << endl;
			break;
		}
		cout << endl;
	}
	return 0;
}

void createList(int n)
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

void display()
{
	cout << "\n========================================\n";

	for (NODE* print = head; print != NULL; print = print->next)
		cout << print->data << " ";

	cout << "\n========================================\n";
}

int count()
{
	size_t count {0};
	for (NODE* counting = head; counting != NULL; counting = counting->next)
		++count;

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