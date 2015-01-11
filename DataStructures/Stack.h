#include <iostream> 

using namespace std;

// Stack node class.
template <class T>
class StackNode
{
public:
	T data;
	StackNode *next;
	StackNode(const T info, StackNode *nextValue = NULL)
	{
		data = info;
		next = nextValue;
	}
	StackNode(StackNode *nextValue = NULL)
	{
		next = nextValue;
	}
};

// Stack class.
template <class T>
class Stack
{
private:
	StackNode<T> *top;
	int size;

public:
	Stack();
	~Stack();

	// Check if stack is empty.
	bool IsEmpty();

	// Clear the stack.
	void Clear();

	// Put an item on top of the stack.
	bool Push(T item);

	// Pop top item off the stack.
	T Pop();

	// Get an item from the top of the stack without removing it.
	T GetTop();

	// Print contents of the stack.
	void Print();
};

template <class T>
Stack<T>::Stack()
{
	// Create empty stack with top pointing to NULL.
	top = NULL;
}

template <class T>
Stack<T>::~Stack()
{
	Clear();
}

template <class T>
bool Stack<T>::IsEmpty()
{
	// If top is NULL then the stack is empty.
	return top == NULL;
}

template <class T>
void Stack<T>::Clear()
{
	StackNode<T> *tmp;

	// Go through each node until the end of the stack.
	while (top != NULL)
	{
		// Point tmp to next node.
		tmp = top->next;

		// Delete current node.
		delete top;

		// Point top to next node.
		top = tmp;
	}
}

template <class T>
bool Stack<T>::Push(T value)
{
	// Replace top with a new stack node and point it to old top node.
	top = new StackNode<T>(value, top);
	
	// Increment the size of the stack.
	size++;

	return true;
}

template <class T>
T Stack<T>::Pop()
{
	// If stack is empty return NULL.
	if (IsEmpty())
	{
		return NULL;
	}

	// Save value from top node.
	T value = top->data;

	// Point tmp to top.
	StackNode<T> *tmp = top;

	// Set top to top's next node.
	top = top->next;

	// Remove top node.
	delete tmp;

	// Update stack size.
	size--;

	return value;
}

template <class T>
T Stack<T>::GetTop()
{
	// If stack is empty return NULL.
	if (IsEmpty())
	{
		return NULL;
	}

	return top->data;
}

template <class T>
void Stack<T>::Print()
{
	StackNode<T> *tmp = top;
	while (tmp != NULL)
	{
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
}