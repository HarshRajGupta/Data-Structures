#include <iostream>
#include <string>
using namespace std;

bool blanced_brackets(string str)
{
	int check {0};
	for (auto i : str)
	{
		if (i == '(' )
		{
			++check;
		}
		if (i == ')' )
		{
			--check;
			if (check < 0)//a + ) b
			{
				return false;
			}
		}
	}
	if (check != 0)
	{
		return false;
	}
	else
	{
		return true;//
	}
}

int main(void)
{
	cout << "Enter the expression : ";
	string str;
	getline(cin, str);
	cout << "\n=====\n";
	cout << boolalpha << blanced_brackets(str);
	cout << "\n=====" << endl;
	return 0;
}