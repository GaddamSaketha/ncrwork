#include<iostream>
using namespace std;
struct queue
{
	int *q;
	int front,rear, size;
};
class _queue_
{
	struct queue que;
public:
	_queue_();
	void enqueue(int);
	int dequeue();
	bool IsEmpty();
	bool IsFull();
	~_queue_();
	void getsize(int);
	void display();
};
_queue_::_queue_()
{
	que.front = -1;
	que.rear = -1;
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
	return(que.rear == (que.size - 1) && que.front==0);
}
bool _queue_::IsEmpty()
{
	return (que.front == -1 && que.rear==-1);
}
void _queue_::enqueue(int ele)
{
	if (!IsFull())
	{
		if (IsEmpty())
		{
			que.q[++que.rear] = ele;
			que.front++;
		}
		else
			que.q[++que.rear] = ele;
	}
	else
		cout << "queue is full" << endl;
}
int _queue_::dequeue()
{
	int x = -999;
	if (!IsEmpty())
	{
		if (que.front == que.rear)
		{
			x = que.q[que.front];
			que.front = -1;
			que.rear = -1;
			return x;
		}
		x = que.q[que.front++];

	}
	else
		cout << "queue is empty";
	return x;
}
void _queue_::display()
{
	for (int i = que.front; i <= que.rear; i++)
		cout << que.q[i];
}
_queue_::~_queue_()
{
	delete que.q;
}
int main()
{
	_queue_ queue1;
	int queue_size;
	cout << "enter size of queue";
	cin >> queue_size;
	queue1.getsize(queue_size);
	int operation_selector;
	int element;
	bool result;
	while (1)
	{
		cout << "select operation on stack" << endl;
		cout << "1.enqueue 2.dequeue 3.isempty 4.isfull 5.display 6.exit" << endl;
		cin >> operation_selector;
		switch (operation_selector)
		{
		case 1: cout << "enter element";

			cin >> element;
			queue1.enqueue(element);
			break;
		case 2:
			element = queue1.dequeue();
			cout << "deleted element is: " << element << endl;
			break;
		case 3: result = queue1.IsEmpty();
			if (result == true)
				cout << "queue is empty";
			else
				cout << "queue is not empty";
			break;
		case 4: result = queue1.IsFull();
			if (result == true)
				cout << "queue is full";
			else
				cout << "queue is not full";
			break;
		case 5: queue1.display();
			break;
		case 6: exit(0);
			break;
		default: cout << "enter valid input";
		}
	}
	return 0;
}