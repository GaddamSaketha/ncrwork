#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node* next;
};
class list
{
	struct node* start;
public:
	list();
	void insert_first(int);
	void insert_last(int);
	void insert_after(int,int);
	void insert_before(int, int);
};
list::list()
{
	start = NULL;
}
void list::insert_first(int ele)
{
	struct node* temp;
	temp = new node;
	temp->data = ele;
	temp->next = start;
	start = temp;
}
void list::insert_last(int ele)//curr points to current node
{
	struct node* temp,*curr;
	temp = new node;
	temp->data = ele;
	temp->next = NULL;
	if(start==NULL)
		start = temp;
	else
	{
		curr = start;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = temp;
	}
}
void list::insert_after(int key,int ele)
{
	if (start != NULL)
	{
		struct node* curr;
		curr = start;
		while (curr != NULL && curr->data != key)
			curr = curr->next;
		if (curr != NULL)
		{
			struct node* temp;
			temp = new node;
			temp->data = ele;
			temp->next = curr->next;
			curr->next = temp;
		}
		else
			cout << "ele not found";
	}
	else
		cout << "list doesnt exist";
}
