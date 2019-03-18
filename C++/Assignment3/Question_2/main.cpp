#include <iostream>
#include <cstdlib>
using namespace std;

// define default capacity of stack
#define SIZE 10

// Class for stack
template <class T>
class stack
{
	T *stack_pointer;
	int top;
	int capacity;

public:
	stack()// constructor
	{
		stack_pointer = new T[SIZE];
		capacity = SIZE;
		top = -1;
	}
	// function to add an element in the stack
	void push(T element)
	{
		if (isFull())
		{
			cout << "OverFlow";
			exit(EXIT_FAILURE);
		}

		cout << "Inserting " << element << endl;
		stack_pointer[++top] = element;
	}
	// function to pop top element from the stack
	T pop()
	{
		if (isEmpty())
		{
			cout << "UnderFlow\n";
			exit(EXIT_FAILURE);
		}

		cout << "Removing " << stack_pointer[top] << endl;
		return stack_pointer[top--];
	}
	// function to return top element in a stack
	T peek()
	{
		if (!isEmpty())
			return stack_pointer[top];
		else
		{
			cout << "UnderFlow\n";
			exit(EXIT_FAILURE);
		}
	}
	// function to return the size of the stack
	int size()
	{
		return top + 1;
	}

	// function to check if the stack is empty or not
	bool isEmpty()
	{
		return top == -1;
	}
	//function to check if the stack is full or not
	bool isFull()
	{
		return top == capacity - 1;
	}
	void operate()
	{
		int option = 0, choice = 0;
		while (1)
		{
			cout << "choose option: 1.push, 2.pop, 3.size, 4.peek\n";
			cin >> option;
			switch (option)
			{
			case 1: {
				cout << "enter element: ";
				T my_element;
				cin >> my_element;
				push(my_element);
				break;
			}
			case 2: {
				cout << "Removed element: " << pop() << endl;
				break;
			}
			case 3: {
				cout << "Number of elements: " << size() << endl;
				break;
			}
			case 4: {
				cout << "Top element: " << peek() << endl;
				break;
			}
			default: {
				cout << "invalid choice, exiting loop\n"; }
			}
			cout << "enter -1 to exit ";
			cin >> choice;
			if (-1 == choice)
				break;
		}
	}
};
//class for complex numbers
class complex
{
	double real;
	double img;

public:
	complex()
	{
		real = 0;
		img = 0;
	}
	complex(double val)
	{
		real = val;
		img = val;
	}
	complex(double val1, double val2)
	{
		real = val1;
		img = val2;
	}
	void display()
	{
		cout << "real : " << real << endl;
		cout << "img : " << img << endl;
	}
	friend ostream& operator<<(ostream& cout, complex c);
	friend istream& operator >> (istream& cin, complex& c);
};
ostream& operator<<(ostream& cout, complex c)
{
	cout << "real: " << c.real;
	cout << "img: " << c.img;
	return cout;
}
istream& operator >> (istream& cin, complex& c)
{
	cin >> c.real;
	cin >> c.img;
	return cin;
}
int main()
{
	stack<float> float_stack;
	stack<int> int_stack;
	stack<char> char_stack;
	stack<complex> complex_stack;
	int choice;
	cout << "enter option 1.float stack 2.int stack 3.char stack 4.complex stack" << endl;
	cin >> choice;
	switch (choice)
	{
	case 1:

		float_stack.operate();
		break;
	case 2:

		int_stack.operate();
		break;
	case 3:

		char_stack.operate();
	case 4:

		complex_stack.operate();
		break;
	default: cout << "entered wrong option";
	}


	return 0;
}