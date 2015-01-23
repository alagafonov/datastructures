#include "Algorithm.h"
#include "Stack.h"

Algorithm::Algorithm()
{
}

Algorithm::~Algorithm()
{
}

double long Algorithm::Factorial(int n)
{
	double long ret = 1;
	Stack<int> stack;

	while (n > 0)
	{
		stack.Push(n--);
	}

	while (!stack.IsEmpty())
	{
		ret *= stack.Pop();
	}

	return ret;
}

string Algorithm::MultiplyStrings(string n1, string n2)
{
	/*int x, y, r, carry = 0;
	for (int i = 0; i < n1.length(); i++)
	{
		x = n1[i] - 48;
		for (int j = 0; j < n2.length(); i++)
		{
			y = n2[i] - 48;
			r = x * y;
		}
	}*/

	/*Stack<char> stack1;
	Stack<char> stack2;

	for (int i = 0; i < n1.length(); i++)
	{
		stack1.Push(n1[i]);
	}

	for (int i = 0; i < n2.length(); i++)
	{
		stack2.Push(n2[i]);
	}

	int x, y, carry = 0;
	while (!stack1.IsEmpty() || !stack2.IsEmpty())
	{
		x = stack1.Pop() - 48;
	}*/

	//stack1.Print();
	//stack2.Print();

	//return "";

	/*for (int j = 0; j < n2.length(); j++)
	{

	}*/
}
