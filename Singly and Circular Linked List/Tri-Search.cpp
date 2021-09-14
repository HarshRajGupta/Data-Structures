#include <iostream>
#include<cstdlib>
using namespace std;

struct node
{
    int data;
    struct node *next;
} *head = NULL, *toe;

typedef struct node NODE;

void create(int n)
{
    if (head == NULL)//Empty List
    {
        head = (NODE*)malloc(sizeof(NODE));
        cin >> head->data;
        head->next = NULL;
        toe = head;
        --n;
    }

    for(int i=0; i<n; ++i)
    {
        NODE* node = (NODE*)malloc(sizeof(NODE));
        cin >> node->data;
        node->next = NULL;//creation of a node
        toe->next = node;
        toe = node;
    }
    return;
}

int count()
{
    int count=0;
    for (NODE *cnt=head; cnt!=NULL;  cnt=cnt->next)
        ++count;

    return count;
}

int tri_search(int value);

int bi_search(int value)
{
	if (toe->data == value)// checking last node
		return count();
	else
	{
		int pos=0;
	    for (NODE* check= head; check!=NULL && check->next!=NULL; check=check->next->next)
	    {
		    if (check->next->data < value || check->next==NULL)
			    pos+=2;
		    else
		    {
			    if (check->data==value)
			    {
				    ++pos;
				    return pos;
			    }
			    else
			    {
				    if(check->next->data==value)
				    {
					    pos+=2;
					    return pos;
				    }
				    else
						return 0;// 0 means number not found
			    }
		    }
	    }
    }
    return 0;
}

int main(void)
{
	printf("List Size : ");
	int size = 0;
	cin >> size;
	cout << "Enter Numbers\n";
	create(size);
	cout << "Number to search for = ";
	int pos=0;
	cin >> pos;
	pos = tri_search(pos);
	if (pos != 0)
	    cout << "Position = " << pos;
	else
		cout << "Number not Found";
	return 0;
}

int tri_search(int value)
{
	if (toe->data == value)// checking last node
		return count();
	else
	{
		int pos=0;
		NODE* check;
	    for (check=head; check!=NULL && check->next!=NULL && check->next->next!=NULL; check=check->next->next->next)
	    {
		    if (check->next->next->data < value || check->next==NULL || check->next->next==NULL)
			    pos+=3;
		    else
		    {
			    if (check->data==value)
			    {
				    ++pos;
				    return pos;
			    }
			    else
			    {
				    if(check->next->data==value)
				    {
					    pos+=2;
					    return pos;
				    }
				    else
				    {
				    	if(check->next->next->data== value)
				    	{
				    		pos+=3;
				    		return pos;
				    	}
				    	else
						    return 0;// 0 means number not found
				    }
			    }
		    }
	    }
	    if(check->next->next == NULL && check->next->data == value)
	    	return count()-1;
    }
    return 0;
}