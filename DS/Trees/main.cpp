#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
class __BST__
{
	struct node* start;
public:
	__BST__();
	int no_of_leaf_nodes(struct node*);
	int no_of_non_leaf_nodes(struct node*);
	int FindMin(struct node*);
	int FindMax(struct node*);
	int height(struct node*);
	void Inorder();
	friend void print(struct node*);
	friend void delete_node(struct node*);
	struct node* Insert(int, struct node*);
	struct node* Delete_ele(int, struct node*);
	~__BST__();
};
__BST__::__BST__()
{
	start = NULL;
}
int __BST__::no_of_leaf_nodes(struct node* curr)
{
	if (curr == 0)
		return 0;
	if (curr->left == NULL && curr->right == NULL)
		return 1;
	return(no_of_leaf_nodes(curr->left) + no_of_leaf_nodes(curr->right));
}
int __BST__::no_of_non_leaf_nodes(struct node* curr)
{
	if (curr == NULL)
		return 0;
	if (curr->left == NULL && curr->right == NULL)
		return 0;
	return(no_of_non_leaf_nodes(curr->left) + no_of_non_leaf_nodes(curr->right)+1);
}
int __BST__::FindMin(struct node* curr)
{
	if (curr != NULL)
	{
		while (curr->left != NULL)
		{
			curr = curr->left;
		}
		return curr->data;
	}
	return -1;
}
int __BST__::FindMax(struct node* curr)
{
	if (curr != NULL)
	{
		while (curr->right != NULL)
		{
			curr = curr->right;
		}
		return curr->data;
	}
	return -1;
}
int __BST__::height(struct node* curr)
{
	if (curr == NULL)
		return -1;
	else
		return(max(height(curr->left),height(curr->right))+1);
}
void __BST__::Inorder()
{
	if (start != NULL)
		print(start);
}
void print(struct node* curr)
{
	if (curr != NULL)
	{
		print(curr->left);
		cout << curr->data;
		print(curr->right);
	}
}
__BST__::~__BST__()
{
	if (start != NULL)
		delete_node(start);
}
void delete_node(node* curr)
{
	if (curr != NULL)
	{
		delete_node(curr->left);
		delete_node(curr->right);
		delete curr;
	}
}
struct node* __BST__::Insert(int ele,struct node* curr)
{
	if (curr == NULL)
	{
		struct node* temp;
		temp = new node;
		temp->data = ele;
		temp->left = NULL;
		temp->right = NULL;
		return temp;
	}
	else
	{
		if (ele < curr->data)
		{
			curr->left = Insert(ele, curr->left);
		}
		else
		{
			curr->right = Insert(ele, curr->right);
		}
		return curr;
	}
}
struct node* __BST__::Delete_ele(int ele, struct node* curr)
{
	if (curr != curr)
	{
		if(ele>curr->data)
	}
}