#include <bits/stdc++.h>
using namespace std;

struct node {
	char data {'0'};
	struct node *next {NULL};
} *head = NULL, *toe = NULL;

typedef struct node NODE;

string postfix(string);

string prefix(string);

bool blanced_brackets(string);

int main(void)
{
	//cout << "Test Cases = ";
	int test_cases {0};
	cin >> test_cases;
	while (test_cases != 0)
	{
		cout << "Enter the expression : ";
		string str;
		getline(cin, str);
		cout << "<------------------->\n";
		if ( blanced_brackets(str) == true )
		{
			string post_fix = postfix(str);
			cout << post_fix << endl;
			cout << "<------------------->\n";
			string pre_fix = prefix(str);
			cout << pre_fix << endl;
		}
		else
		{
			cout << boolalpha << blanced_brackets(str) << endl;
		}
		cout << "<------------------->\n" << endl;
		--test_cases;
	}
	return 0;
}

void push(char x)// Pushes in the Stack >>> Insertion in Begining
{
	NODE* new_node = (NODE*)malloc(sizeof(NODE));
	new_node->data = x;
	new_node->next = head;
	head = new_node;
}

void pop(string &fix)
{
	if (head->data != '(' && head->data != ')')// '(' don't appear in PostFix
	{
		fix.push_back(head->data);
	}
	if (head != NULL && head->next == NULL)// Emptying the Stack
	{
		free(head);
		head = NULL;
	}
	else if (head != NULL)// Deletion at Begining
	{
		NODE* temp = head->next;
		free(head);
		head = temp;
	}
}

int precedence(char x)// Precedence Checker
{
	if (x == '(' || x == ')')
	{
		return 4;
	}
	else if (x == '^')
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

string postfix(string str)
{
	string post_fix;

	for (auto i : str)// staring the string
	{
		if (i == '(' || i == ')' || i == '^' || i == '/' || i == '*' || i == '+' || i == '-')// i is operator or not
		{
			if (i == ')')
			{
				while (head != NULL && head->next != NULL && head->data != '(')
				{
					pop(post_fix);
				}
				if (head != NULL)
				{
					pop(post_fix); // popping out '('
				}
			}
			else if (head == NULL) // Stack is Empty
			{
				push(i);
			}
			else if (precedence(head->data) < precedence(i) || head->data == '(' ) //
			{
				push(i);
			}
			else
			{
				while (head != NULL && precedence(head->data) >= precedence(i))
				{
					pop(post_fix);
				}
				push(i);
			}
		}
		else// i is a operand
		{
			post_fix.push_back(i);
		}
	}
	while (head != NULL)
	{
		pop(post_fix);
	}
	return post_fix;
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

				pop(pre_fix); // popping out '('
			}
			else if (head == NULL) // Stack is Empty
			{
				push(i);
			}
			else if (precedence(head->data) <= precedence(i) || head->data == ')' ) //
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

bool blanced_brackets(string str)// Cecking whether '(' and ')' are in pairs..?
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
			if (check < 0)// ')' closing brace without opening
			{
				return false;
			}
		}
	}
	if (check > 0)// ')' is missing
	{
		return false;
	}
	else
		return true;
}