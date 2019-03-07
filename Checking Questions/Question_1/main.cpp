#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
double result = 0;
double Add(double a, double b);
double Mul(double a, double b);
double Sub(double a, double b);
double Div(double a, double b);
class char_stack
{
	struct sta
	{
		int top;
		char *elem;
		int length;
	}stack;
public:
	char_stack()
	{
		stack.length = 0;
		stack.elem = NULL;
		stack.top = -1;
	}
	char_stack(int size)
	{
		stack.length = size;
		stack.elem = new char[size];
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
		if (stack.top == stack.length - 1)
		{
			return true;
		}
		return false;
	}
	void Push(char ele)
	{
		if (stack.top == stack.length - 1)
		{
			cout << "Stack Full";
			return;
		}
		else
		{
			stack.elem[++stack.top] = ele;
		}
	}
	char Pop()
	{
		int x = -999;
		if (stack.top == -1)
		{
			return x;
		}
		x = stack.elem[stack.top--];
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
			x = stack.elem[stack.top];
			return x;
		}
	}
	void Display()
	{
		for (int i = 0; i <= stack.top; i++)
		{
			cout << stack.elem[i];
		}
	}
	~char_stack()
	{
		delete (stack.elem);
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
class double_stack
{
	struct sta
	{
		int top;
		double *elem;
		int length;
	}stack;
public:
	double_stack()
	{
		stack.length = 0;
		stack.elem = NULL;
		stack.top = -1;
	}
	double_stack(int size)
	{
		stack.length = size;
		stack.elem = new double[size];
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
		if (stack.top == stack.length - 1)
		{
			return true;
		}
		return false;
	}
	void Push(double x)
	{
		if (stack.top == stack.length - 1)
		{
			cout << "Stack Full";
			return;
		}
		else
		{
			stack.elem[++stack.top] = x;
		}
	}
	double Pop()
	{
		double x = -999;
		if (stack.top == -1)
		{
			cout << "Stack Empty";
			return x;
		}
		else
		{
			x = stack.elem[stack.top--];
			return x;
		}
	}
	double Peek()
	{
		double x = -999;
		if (stack.top == -1)
		{
			cout << "Stack Empty";
			return x;
		}
		else
		{
			x = stack.elem[stack.top];
			return x;
		}
	}
	void Display()
	{
		for (int i = 0; i <= stack.top; i++)
		{
			cout << stack.elem[i] << endl;
		}
	}
	~double_stack()
	{
		delete (stack.elem);
	}
};
int main()
{
	char input_string[100];
	cout << "Enter the string";
	cin >> input_string;
	char result_string[100];
	char_stack stack1(100);
	char current_char;
	int res_index = 0;
	double f;
	for (int i = 0; i < strlen(input_string); i++)
	{
		current_char = input_string[i];
		if (isalpha(current_char))
		{
			cout << "wrong input";
			return -1;
		}
		else if (isdigit(current_char))
		{
			result_string[res_index++] = current_char;
		}
		else if (current_char == '(')
		{
			stack1.Push(current_char);
		}
		else if (current_char == ')')
		{
			while (stack1.Peek() != '(')
			{
				result_string[res_index++] = stack1.Pop();
			}
			stack1.Pop();
		}
		else if (stack1.isEmpty())
		{
			stack1.Push(current_char);
		}
		else if (Precedence(current_char) > Precedence(stack1.Peek()))
		{
			stack1.Push(current_char);
		}
		else
		{
			while (Precedence(current_char) <= Precedence(stack1.Peek()))
			{

				result_string[res_index++] = stack1.Pop();
			}

			stack1.Push(current_char);
		}
	}
	while (!stack1.isEmpty())
	{
		result_string[res_index++] = stack1.Pop();
	}
	result_string[res_index] = '\0';
	cout << "Result String is: " << result_string << endl;
	double_stack stack2(100);
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
			double num1 = stack2.Pop();
			double num2 = stack2.Pop();
			switch (ch)
			{
			case '+': stack2.Push(Add(num1, num2));
				break;
			case '-': stack2.Push(Sub(num2, num1));
				break;
			case '*': stack2.Push(Mul(num1, num2));
				break;
			case '/': f = Div(num2, num1);
				if (f == -1)
				{
					cout << "invalid operation" << endl;
					return -1;
				}
				else
					stack2.Push(result);
				break;
			default: cout << "wrong input" << endl;
				break;
			}
		}
	}
	cout << "Result is: " << stack2.Pop();
	return 0;
}