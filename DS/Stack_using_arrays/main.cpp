#include<iostream>
using namespace std;
struct queue
{
	int *q;
	int top, size;
};
class _queue_
{
	struct queue que;
public:
	_queue_();
	void enqueue(int);
	int dequeue();
	int peek();
	bool IsEmpty();
	bool IsFull();
	~_queue_();
	void getsize(int);
	void display();
};
_queue_::_queue_()
{
	que.top = -1;
	que.q = NULL;
	que.size = 0;
}
void _queue_::getsize(int n)
{
	que.size = n;
	que.q = new int[n];

}
bool _queue_::IsFull()
{
	return(que.top == (que.size - 1));
}
bool _queue_::IsEmpty()
{
	return (que.top == -1);
}
void _queue_::enqueue(int ele)
{
	if (!IsFull())
	{
		que.q[++que.top] = ele;
	}
	else
		cout << "stack is full" << endl;
}
int _queue_::dequeue()
{
	int x = -999;
	if (!IsEmpty())
		x = que.q[que.top--];
	else
		cout << "stack is empty";
	return x;
}
int _queue_::peek()
{
	int x = -999;
	if (!IsEmpty())
		x = que.q[que.top];
	else
		cout << "empty";
	return x;
}
void _queue_::display()
{
	for (int i = 0; i <= que.top; i++)
		cout << que.q[i];
}
_queue_::~_queue_()
{
	delete que.q;
}
int main()
{
	_queue_ stack1;
	int stack_size;
	cout << "enter size of stack";
	cin >> stack_size;
	stack1.getsize(stack_size);
	int operation_selector;
	int element;
	bool result;
	while (1)
	{
		cout << "select operation on stack" << endl;
		cout << "1.push 2.pop 3.peek 4.isempty 5.isfull 6.display 7.exit" << endl;
		cin >> operation_selector;
		switch (operation_selector)
		{
		case 1 : cout << "enter element";
			
			cin >> element;
			stack1.enqueue(element);
			break;
		case 2 : 
			element = stack1.dequeue();
			cout << "element is: " << element << endl;
			break;
		case 3 :
			element = stack1.peek();
			cout << " top element is: " << element << endl;
			break;
		case 4: result = stack1.IsEmpty();
			if (result == true)
				cout << "stack is empty";
			else
				cout << "stack is not empty";
			break;
		case 5: result = stack1.IsFull();
			if (result == true)
				cout << "stack is full";
			else
				cout << "stack is not full";
			break;
		case 6: stack1.display();
			break;
		case 7: exit(0);
			break;
		default: cout << "enter valid input";
		}
	}
	return 0;
}