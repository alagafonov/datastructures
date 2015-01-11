#include <iostream> 
#include "List.h"

using namespace std;

// Doubly linked list node class.
// Stores node contents, a pointer to the next node and a pointer to the previous node.
template <class T>
class DLinkedListNode
{
public:
	T data;
	DLinkedListNode *next;
	DLinkedListNode *prev;
	DLinkedListNode(const T info, DLinkedListNode *nextValue = NULL, DLinkedListNode *prevValue = NULL)
	{
		data = info;
		next = nextValue;
		prev = prevValue;
	}
	DLinkedListNode(DLinkedListNode *nextValue = NULL, DLinkedListNode *prevValue = NULL)
	{
		next = nextValue;
		prev = prevValue;
	}
};

// Doubly linked list class.
template <class T>
class DLinkedList : public List<T>
{
private:
	DLinkedListNode<T> *head, *tail;

public:
	DLinkedList();
	~DLinkedList();

	// Check if list is empty.
	bool IsEmpty();

	// Appent item to the top of the list.
	bool AppendToHead(T value);

	// Appent item to the end of the list.
	bool AppendToTail(T value);

	// Delete tail node.
	void DeleteTail();

	// Check if node exists in the list.
	bool IsInList(T value);

	// Print contents of the list.
	void Print();

	// Print contents of the list in reverse.
	void PrintBackwards();
};

template <class T>
DLinkedList<T>::DLinkedList()
{
	// Create empty list with head and tail pointing to NULL.
	head = tail = NULL;
}

template <class T>
DLinkedList<T>::~DLinkedList()
{
	DLinkedListNode<T> *tmp;

	// Go through each node until the end of the list.
	while (head != NULL)
	{
		// Point tmp to next node.
		tmp = head->next;

		// Delete current node.
		delete head;

		// Point head to next node.
		head = tmp;
	}
}

template <class T>
bool DLinkedList<T>::IsEmpty()
{
	// If head is NULL then the list is empty.
	return head == NULL;
}

template <class T>
bool DLinkedList<T>::AppendToHead(T value)
{
	// Create tmp node to store pointer to head.
	DLinkedListNode<T> *tmp = head;

	// Replace head with a new linked list node and point it to old head.
	head = new DLinkedListNode<T>(value, head, NULL);

	// If this is the first element being inserted then also point tail to head.
	if (tail == NULL)
	{
		tail = head;
	}

	// Otherwise point old head's previous pointer back to head
	else
	{
		tmp->prev = head;
	}
	return true;
}

template <class T>
bool DLinkedList<T>::AppendToTail(T value)
{
	// If the list is empty then point head to the new node and tail to head.
	if (head == NULL)
	{
		head = new DLinkedListNode<T>(value);
		tail = head;
		return true;
	}

	// If the list is not empty then point tail to new node and new node's previous pointer to the old tail
	tail = new DLinkedListNode<T>(value, NULL, tail);
	
	// Now point old tail to new tail.
	tail->prev->next = tail;
	return true;
}

template <class T>
void DLinkedList<T>::DeleteTail()
{
	// Empty list.
	if (tail == NULL)
	{
		return;
	}

	// List has only one node.
	if (tail == head)
	{
		// Delete the node.
		delete tail;

		// Reset the list to empty state.
		tail = head = NULL;
		return;
	}

	// Point tmp to tail's previous node
	DLinkedListNode<T> *tmp = tail->prev;

	// Delete tail.
	delete tail;

	// Set tail to previous node.
	tail = tmp;

	// Set new tail's next node to NULL
	tail->next = NULL;

	return;
}

template <class T>
bool DLinkedList<T>::IsInList(T value)
{
	// Point tmp to head.
	DLinkedListNode<T> *tmp = head;

	// Go through each node in the list until we reach tail.
	while (tmp != NULL)
	{
		// If value is found return true.
		if (tmp->data == value)
		{
			return true;
		}

		// Point tmp to next node.
		tmp = tmp->next;
	}

	return false;
}

template <class T>
void DLinkedList<T>::Print()
{
	DLinkedListNode<T> *tmp = head;
	while (tmp != NULL)
	{
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
}

template <class T>
void DLinkedList<T>::PrintBackwards()
{
	DLinkedListNode<T> *tmp = tail;
	while (tmp != NULL)
	{
		cout << tmp->data << " ";
		tmp = tmp->prev;
	}
}