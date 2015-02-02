#include "Algorithm.h"
#include "Stack.h"

Algorithm::Algorithm()
{
}

Algorithm::~Algorithm()
{
}

string Algorithm::Factorial(int n)
{
	string ret = "1";
	Stack<string> stack;

	// Add numbers n..1 to stack converting them to strings.
	while (n > 0)
	{
		stack.Push(IntToString(n--));
	}

	// While stack is not empty keep multiplying numbers using sring multiplication function.
	while (!stack.IsEmpty())
	{
		ret = MultiplyStrings(ret, stack.Pop());
	}

	return ret;
}

string Algorithm::MultiplyStrings(string n1, string n2)
{
	// Create result string and set its length to the sum of lengths of input strings and set all characters to 0.
	string result;
	result.resize(n1.length() + n2.length(), '0');

	// Define intermediate variables.
	int x, s, r, carry;

	// Iterate over first string in reverse order.
	for (int i = n1.length() - 1; i >= 0; i--)
	{
		carry = 0;
		
		// Get ith character from first string and convert it to integer
		x = CharToInt(n1[i]);
		
		// Iterate over seond string in reverse order.
		for (int j = n2.length() - 1; j >= 0; j--)
		{
			// Calculate product of ith number from first string and jth number from second string.
			// Then add contents of the current position in the result string and carry forward variable.
			s = x * CharToInt(n2[j]) + CharToInt(result[j + i + 1]) + carry;

			// Get second digit from the result of the product e.g. if s = 12 then r = 2 if s = 4 then r = 4.
			r = s % 10;

			// Set first digit to be carried forward e.g. if s = 12 then carry = 1 if s = 2 then carry = 0.
			carry = (s - r) / 10;

			// Add r to the result string.
			result[j + i + 1] = IntToChar(r);
		}

		// Add carry forward to the result string.
		result[i] = IntToChar(carry);
	}

	// Because we are adding numbers to the result string from the back in some cases there will be a leading 0 in front of the string.
	// For example if input is x = '100', y = '1' then result string length will be length of (x) + length of (y) = 4
	// so the result will be stored as 0100 so in this case we erase the first digit.
	if (result[0] == '0')
	{
		result.erase(result.begin());
	}

	return result;
}

int Algorithm::BinarySearch(int *input, int value, int start, int end)
{
	// If array is exhausted and nothing was found then return not found flag.
	if (start > end)
	{
		return -1;
	}

	// Calculate midpoint of the array.
	int mp = (end + start) / 2;

	// Found the value return the position.
	if (input[mp] == value)
	{
		return mp;
	}

	// If value is smaller than midpoint then we need to look at first half of the partition.
	else if (input[mp] > value)
	{
		return BinarySearch(input, value, start, mp - 1);
	}

	// If value is bigger than midpoint then we need to look at second half of the partition.
	else
	{
		return BinarySearch(input, value, mp + 1, end);
	}
}

void Algorithm::BubbleSort(int *input, int length)
{
	// Go through all elements in the array.
	for (int i = 0; i < length - 1; i++)
	{
		// Start from the end of the array and compare elements at position j with j - 1.
		for (int j = length - 1; j > i; j--)
		{
			// If element at position closer to the end of the array is smaller than the one in front of it then swap elements.
			if (input[j] < input[j - 1])
			{
				Swap(input, j, j - 1);
			}
		}
	}
}

void Algorithm::QuickSort(int *input, int start, int end)
{
	// Make sure that we have at least two items to sort.
	if (end > start)
	{
		// Choose a pivot element from the middle.
		int pivotIndex = (end + start) / 2;
		int pivot = input[pivotIndex];

		// Swap it with the last element in the array.
		Swap(input, end, pivotIndex);

		// Keep track of the position of the last element that is greater than pivot.
		int swapPos = start;

		// Loop through array start and end bounds
		for (int i = start; i < end; i++)
		{
			// Found element that is smaller than pivot.
			if (input[i] < pivot)
			{
				// Swap it with the position of the element that is bigger than pivot.
				Swap(input, i, swapPos++);
			}
		}

		// Put pivot element where all other elements are smaller than pivot itself.
		Swap(input, end, swapPos);

		// Sort partition before pivot element.
		QuickSort(input, start, swapPos - 1);

		// Sort partition after pivot element.
		QuickSort(input, swapPos + 1, end);

	}
}

void Algorithm::Swap(int *input, int pos1, int pos2)
{
	int tmp = input[pos1];
	input[pos1] = input[pos2];
	input[pos2] = tmp;
}

int Algorithm::CharToInt(char c)
{
	return c - 48;
}

char Algorithm::IntToChar(int i)
{
	return i + 48;
}

string Algorithm::IntToString(int n)
{
	// If n = 0 then just return string containing "0".
	if (n == 0)
	{
		return "0";
	}

	int r;
	bool neg = false;
	string ret;
	
	// Check if n is a negative integer.
	if (n < 0)
	{
		n = -n;
		neg = true;
	}

	// Convert n to string digit by digit
	while (n != 0)
	{
		r = n % 10;
		n = (n - r) / 10;
		ret = IntToChar(r) + ret;
	}

	// Add "-" sign if input is a negative integer.
	if (neg)
	{
		ret = '-' + ret;
	}

	return ret;
}
