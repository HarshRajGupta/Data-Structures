#include <iostream>
#include "Linked_List.h"
using namespace std;

int main(int argc, char const **argv)
{
	int ch {0};
	while (ch != 9)
	{
		cout << "1.Create\n2.Insert\n3.Delete\n4.Count\n5.More" << endl;
		cout << "Enter your choice : ";
		int n {0};
		cin >> ch;

		switch (ch)
		{
		case 1: cout << "\nList Size : ";
		        cin >> n;
		        cout << "Enter " << n << " numbers" << endl;
		        create_list(n);
		        break;

		case 2: cout << "\n1.At begining\n2.At end\n3.Custom" << endl;
		        cin >> n;
		        if(n == 1)
		        {
		        	insert(0);
		        }
		        else if (n == 2)
		        {
		        	create_list(1);
		        }
		        else
		        {
		        	cout << "Position : ";
		        	cin >> n;
		        	insert(n);
		        }
		        break;

		case 3: cout << "\n1.Delete Node\n2.Delete Number" << endl;
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

		case 4: cout << "\nList has " << count() << " elements" << endl;
		        break;

		case 5: cout << "\n1.Search\n2.See Value\n3.Sort\n4.Rotate\n5.Occurence" << endl;
		        cout << "Enter your choice : ";
		        cin >> ch;

		        switch(ch)
		        {
		        case 1: cout << "\nEnter the number : ";
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

		        case 2: cout << "\n1.From begining\n2.From end" << endl;
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

		        case 4: cout << "\n1.Right\n2.Left\n";
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