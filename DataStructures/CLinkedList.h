#include <iostream> 
#include "List.h"

using namespace std;

// Circular linked list node class.
// Stores node contents and the pointer to next node.
template <class T>
class CLinkedListNode
{
public:
	T data;
	CLinkedListNode *next;
	CLinkedListNode(const T info, CLinkedListNode *nextValue = NULL)
	{
		data = info;
		next = nextValue;
	}
	CLinkedListNode(CLinkedListNode *nextValue = NULL)
	{
		next = nextValue;
	}
};

// Singly linked list class.
template <class T>
class CLinkedList : public List<T>
{
private:
	CLinkedListNode<T> *tail, *current;

public:
	CLinkedList();
	~CLinkedList();

	// Check if list is empty.
	bool IsEmpty();

	// Appent item to the end of the list.
	void AppendToTail(T value);

	// Gets current node and changes current pointer to next node.
	T GetCurrentNode();

	// Print contents of the list.
	void Print();
};

template <class T>
CLinkedList<T>::CLinkedList()
{
	// Create empty list with tail pointing to NULL.
	tail = current = NULL;
}

template <class T>
CLinkedList<T>::~CLinkedList()
{
	if (IsEmpty())
	{
		return;
	}

	CLinkedListNode<T> *tmp = tail->next;

	// Go through each node until tail is reached.
	while (tmp != tail)
	{
		// Delete head node and repoint tail to new head.
		tail->next = tmp->next;

		// Delete current node.
		delete tmp;

		// Point tmp to new head node.
		tmp = tail->next;
	}

	// Delete tail.
	delete tmp;
}

template <class T>
bool CLinkedList<T>::IsEmpty()
{
	// If tail is NULL then the list is empty.
	return tail == NULL;
}

template <class T>
void CLinkedList<T>::AppendToTail(T value)
{
	// If list is empty then create new node, point tail to it and point tail to itself
	if (tail == NULL)
	{
		tail = new CLinkedListNode<T>(value);
		tail->next = tail;
	}

	// Otherwise append new node to tail and 
	else
	{
		// Create temporaty pointer to tail.
		CLinkedListNode<T> *tmp = tail;

		// Create new tail node and point it to old tail's next node
		tail = new CLinkedListNode<T>(value, tail->next);

		// Point old tail to new tail.
		tmp->next = tail;

	}
}

template <class T>
T CLinkedList<T>::GetCurrentNode()
{
	// List is empty.
	if (IsEmpty())
	{
		return NULL;
	}

	// Current pointer has not been set.
	if (current == NULL)
	{
		// Point to head node.
		current = tail->next;
	}

	// Get data from current node.
	T data = current->data;

	// Set current node to the next node.
	current = current->next;

	// Return data.
	return data;
}

template <class T>
void CLinkedList<T>::Print()
{
	if (IsEmpty())
	{
		return;
	}

	CLinkedListNode<T> *tmp = tail->next;
	while (tmp != tail)
	{
		cout << tmp->data << " ";
		tmp = tmp->next;
	}

	cout << tail->data << " ";
}