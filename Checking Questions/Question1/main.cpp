#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#define SIZE 100
int result = 0;
int Add(int a, int b);
int Mul(int a, int b);
int Sub(int a, int b);
float Div(int a, int b);
using namespace std;
class _Stack_
{
	struct sta
	{
		int top;
		char *elements;
		int size;
	}stack;
public:
	_Stack_()
	{
	}
	_Stack_(int size)
	{
		stack.size = size;
		stack.elements = new char[size];
		stack.top = -1;
	}
	bool isEmpty()
	{
		if (stack.top == -1)
			return true;
		return false;
	}
	bool isFull()
	{
		if (stack.top == stack.size - 1)
		{
			return true;
		}
		return false;
	}
	void Push(char ele)
	{
		if (stack.top == stack.size - 1)
		{
			cout << "Stack Full";
			return;
		}
		else
		{
			stack.elements[++stack.top] = ele;
		}
	}
	char Pop()
	{
		int x = -999;
		if (stack.top == -1)
		{
			return x;
		}
		x = stack.elements[stack.top--];
		return x;
	}
	char Peek()
	{
		int x = -999;
		if (stack.top == -1)
		{
			return x;
		}
		else
		{
			x = stack.elements[stack.top];
			return x;
		}
	}
	void Display()
	{
		for (int i = 0; i <= stack.top; i++)
		{
			cout << stack.elements[i];
		}
	}
	~_Stack_()
	{
		delete (stack.elements);
	}
};
int Precedence(char x)
{
	if (x == '*' || x == '/')
		return  3;
	else if (x == '+' || x == '-')
		return 2;
	else
		return 1;
}
class _StackInt_
{
	struct sta
	{
		int top;
		int *elements;
		int size;
	}stack;
public:
	_StackInt_()
	{
	}
	_StackInt_(int size)
	{
		stack.size = size;
		stack.elements = new int[size];
		stack.top = -1;
	}
	bool isEmpty()
	{
		if (stack.top == -1)
			return true;
		return false;
	}
	bool isFull()
	{
		if (stack.top == stack.size - 1)
		{
			return true;
		}
		return false;
	}
	void Push(int x)
	{
		if (stack.top == stack.size - 1)
		{
			cout << "Stack Full";
			return;
		}
		else
		{
			stack.elements[++stack.top] = x;
		}
	}
	int Pop()
	{
		int x = -999;
		if (stack.top == -1)
		{
			cout << "Stack Empty";
			return x;
		}
		else
		{
			x = stack.elements[stack.top--];
			return x;
		}
	}
	int Peek()
	{
		int x = -999;
		if (stack.top == -1)
		{
			cout << "Stack Empty";
			return x;
		}
		else
		{
			x = stack.elements[stack.top];
			return x;
		}
	}
	void Display()
	{
		for (int i = 0; i <= stack.top; i++)
		{
			cout << stack.elements[i] << endl;
		}
	}
	~_StackInt_()
	{
		delete (stack.elements);
	}
};
int main()
{
	char input_string[SIZE];
	cout << "Enter the string";
	cin >> input_string;
	char result_string[SIZE];
	_Stack_ stack1(10);
	int curr = 0;
	char ch;
	int k = 0;
	for (int i = 0; i < strlen(input_string); i++)
	{
		ch = input_string[i];
		if (isdigit(ch) || isalpha(ch))
		{
			result_string[k++] = ch;
		}
		else if (ch == '(')
		{
			stack1.Push(ch);
		}
		else if (ch == ')')
		{
			while (stack1.Peek() != '(')
			{
				result_string[k++] = stack1.Pop();
			}
			stack1.Pop();
		}
		else if (stack1.isEmpty())
		{
			stack1.Push(ch);
		}
		else if (Precedence(ch) > Precedence(stack1.Peek()))
		{
			stack1.Push(ch);
		}
		else
		{
			while (Precedence(ch) <= Precedence(stack1.Peek()))
			{
				
				result_string[k++] = stack1.Pop();
			}

			stack1.Push(ch);
		}
	}
	while (!stack1.isEmpty())
	{
		result_string[k++] = stack1.Pop();
	}
	result_string[k] = '\0';
	cout << "Result String is: " << result_string << endl;
	_StackInt_ stack2(10);
	for (int i = 0; i < strlen(result_string); i++)
	{
		char ch;
		ch = result_string[i];
		if (isdigit(ch) && !stack2.isFull())
		{
			stack2.Push(ch - '0');
		}
		else
		{
			int a = stack2.Pop();
			int b = stack2.Pop();
			switch (ch)
			{
			case '+': stack2.Push(Add(a, b));
				break;
			case '-': stack2.Push(Sub(b, a));
				break;
			case '*': stack2.Push(Mul(a, b));
				break;
			case '/': stack2.Push(Div(b, a));
				break;
			}
		}
	}
	cout << "Result is: " << stack2.Pop();
	return 0;
}