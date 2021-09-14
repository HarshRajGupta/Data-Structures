#include <bits/stdc++.h>
using namespace std;

struct node
{
	string data;
	struct node *next {NULL};
} *head = NULL, *toe = NULL;

typedef struct node NODE;

void push(char x)// Pushes in the Stack >>> Insertion in Begining
{
	NODE* new_node = (NODE*)malloc(sizeof(NODE));
	new_node->data = x;
	new_node->next = head;
	head = new_node;
}

void push_evaluation(string x)// Pushes in the Stack >>> Insertion in Begining
{
	NODE* new_node = (NODE*)malloc(sizeof(NODE));
	new_node->data = x;
	new_node->next = head;
	head = new_node;
}

void pop(string &post_fix)
{
	if (head->data != "(" && head->data != ")")// '(' don't appear in PostFix
	{
		post_fix.push_back(head->data.at(0));
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
				while (head->data != "(" && head->next != NULL)
				{
					pop(post_fix);
				}

				pop(post_fix); // popping out '('
			}
			else if (head == NULL) // Stack is Empty
			{
				push(i);
			}
			else if (precedence(head->data.at(0)) < precedence(i) || head->data == "(" ) //
			{
				push(i);
			}
			else
			{
				while (head != NULL && precedence(head->data.at(0)) >= precedence(i))
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

void operate(char x)	
{
	cout << 2;
	string o2 = head->data;
	NODE* temp = head->next;
	free(head);
	head = temp;
	string o1 = head->data;
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
	string push = '(' + o1 + x + o2 + ')';
	push_evaluation(push);
}

string evaluate(string post_fix)
{
	for(auto i: post_fix)
	{
		cout << i;
		if (i == '^' || i == '/' || i == '*' || i == '+' || i == '-')// i is operator or not
		{
			operate(i);
		}
		else
		{
			push(i);
			cout << 's';
		}
	}
	string result = head->data;
	while(head != NULL)
	{
		cout << 1;
		NODE* temp = head->next;
		free(head);
		head = temp;
	}
	return result;
}

int main(void)
{
	cout << "Enter the expression : ";
	string str;
	getline(cin, str);
	cout << "<------------------->\n";
	if ( blanced_brackets(str) == true )
	{
		string post_fix = postfix(str);
		cout << post_fix << endl;
		post_fix = evaluate(post_fix);
		cout << post_fix << endl;
	}
	else
	{
		cout << boolalpha << blanced_brackets(str) << endl;
	}
	cout << "<------------------->\n";
	return 0;
}