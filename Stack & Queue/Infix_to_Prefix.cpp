#include <bits/stdc++.h>
using namespace std;

struct node
{
	char data {'0'};
	struct node *next {NULL};
} *head = NULL, *toe = NULL;

typedef struct node NODE;

bool blanced_brackets(string);

string prefix(string);

int main(void)
{
	cout << "Enter the expression : ";
	string str;
	getline(cin, str);
	cout << "\n======================\n";
	if ( blanced_brackets(str) == true )
	{
		string pre_fix = prefix(str);
		cout << pre_fix;
	}
	else
	{
		cout << boolalpha << blanced_brackets(str);
	}
	cout << "\n======================\n";
	return 0;
}

void push(char x)
{
	NODE* new_node = (NODE*)malloc(sizeof(NODE));
	new_node->data = x;
	new_node->next = head;
	head = new_node;
}

void pop(string &pre_fix)
{
	if (head->data != ')')
	{
		pre_fix.push_back(head->data);
	}
	if (head != NULL && head->next == NULL)
	{
		free(head);
		head = NULL;
	}
	else if (head != NULL)
	{
		NODE* temp = head->next;
		free(head);
		head = temp;
	}
}

int precedence(char x)
{
	if (x == '^')
	{
		return 3;
	}
	else if (x == '/' || x == '*')
	{
		return 2;
	}
	else if (x == '+' || '-')
	{
		return 1;
	}
	else
		return 0;

}

string prefix(string str)
{
	string pre_fix;
	reverse(str.begin(), str.end());
	
	for (auto i : str)// staring the string
	{
		if (i == '(' || i == ')' || i == '^' || i == '/' || i == '*' || i == '+' || i == '-')// i is operator or not
		{
			if (i == '(')
			{
				while (head->data != ')' && head->next != NULL)
				{
					pop(pre_fix);
				}

				pop(pre_fix); // popping out ')'
			}
			else if (head == NULL || i == ')') // Stack is Empty
			{
				push(i);
			}
			else if (precedence(head->data) <= precedence(i) || head->data == ')' )
			{
				push(i);
			}
			else
			{
				while (head != NULL && precedence(head->data) > precedence(i))
				{
					pop(pre_fix);
				}
				push(i);
			}
		}
		else// i is a operand
		{
			pre_fix.push_back(i);
		}
	}
	while (head != NULL)
	{
		pop(pre_fix);
	}
	reverse(pre_fix.begin(), pre_fix.end());
	return pre_fix;
}

bool blanced_brackets(string str)
{
	int check {0};
	for (auto i : str)
	{
		if (i == '(' )
		{
			++check;
		}
		else if (i == ')' )
		{
			--check;
			if (check < 0)
			{
				return false;
			}
		}
	}
	if (check > 0)
	{
		return false;
	}

	return true;
}