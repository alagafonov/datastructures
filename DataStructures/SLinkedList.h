#include <iostream> 
#include "List.h"

using namespace std;

// Singly linked list node class.
// Stores node contents and the pointer to next node.
template <class T>
class SLinkedListNode
{
public:
	T data;
	SLinkedListNode *next;
	SLinkedListNode(const T info, SLinkedListNode *nextValue = NULL)
	{
		data = info;
		next = nextValue;
	}
	SLinkedListNode(SLinkedListNode *nextValue = NULL)
	{
		next = nextValue;
	}
};

// Singly linked list class.
template <class T>
class SLinkedList : public List<T>
{
	private:
		int pos;
		SLinkedListNode<T> *head, *tail;
		SLinkedListNode<T> *GetNode(int p);

		// Get Nth node from the tail using recursion - the actual recursive function.
		T SLinkedList<T>::_GetNthElementFromTailRec(int n, SLinkedListNode<T> *node);

	public:
		SLinkedList();
		~SLinkedList();

		// Check if list is empty.
		bool IsEmpty();

		// Appent item to the top of the list.
		bool AppendToHead(T value);

		// Appent item to the end of the list.
		bool AppendToTail(T value);

		// Insert data at position i.
		bool InsertAtPos(int i, T value);

		// Delete node at position i.
		bool DeleteAtPos(int i);

		// Get node at position i.
		T GetContentAtPos(int i);

		// Get Nth node from the tail.
		T SLinkedList<T>::GetNthElementFromTail(int n);

		// Get Nth node from the tail using recursion.
		T SLinkedList<T>::GetNthElementFromTailRec(int n);

		// Get middle node content.
		T SLinkedList<T>::GetMiddleNodeContent();

		// Reverse list.
		void SLinkedList<T>::ReverseList();

		// Check if node exists in the list.
		bool IsInList(T value);

		// Print contents of the list.
		void Print();
};

template <class T>
SLinkedList<T>::SLinkedList()
{
	// Create empty list with head and tail pointing to NULL.
	head = tail = NULL;
}

template <class T>
SLinkedList<T>::~SLinkedList()
{
	SLinkedListNode<T> *tmp;

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
bool SLinkedList<T>::IsEmpty()
{
	// If head is NULL then the list is empty.
	return head == NULL;
}

template <class T>
bool SLinkedList<T>::AppendToHead(T value)
{
	// Replace head with a new linked list node and point it to head.
	head = new SLinkedListNode<T>(value, head);

	// If this is the first element being inserted then also point tail to head.
	if (tail == NULL)
	{
		tail = head;
	}
	return true;
}

template <class T>
bool SLinkedList<T>::AppendToTail(T value)
{
	// Create new linked list node.
	SLinkedListNode<T> *node = new SLinkedListNode<T>(value);

	// If the list is empty then point head to the new node and tail to head.
	if (head == NULL)
	{
		head = node;
		tail = head;
		return true;
	}

	// The list is not empty set tail's next pointer to new node and point to tail to new node.
	tail->next = node;
	tail = node;
	return true;
}

template <class T>
bool SLinkedList<T>::InsertAtPos(int i, T value)
{
	// Make sure position is a positive number.
	if (i < 0)
	{
		return false;
	}

	// Position is at head node.
	if (i == 0 && head != NULL)
	{
		return AppendToHead(value);
	}

	// Get node at a previous position.
	SLinkedListNode<T> *tmp = GetNode(i - 1);

	// If node at position i is NULL then we simply append to tail.
	if (tmp == NULL)
	{
		return AppendToTail(value);
	}

	// Create new linked list node and point it to the node at the current position.
	SLinkedListNode<T> *node = new SLinkedListNode<T>(value, tmp->next);

	// Point previous node to the new node.
	tmp->next = node;

	return true;
}

template <class T>
bool SLinkedList<T>::DeleteAtPos(int i)
{
	// Make sure it is a valid position number.
	if (i < 0)
	{
		return false;
	}

	SLinkedListNode<T> *tmp;

	// Position is at head node.
	if (i == 0 && head != NULL)
	{
		// Point tmp to head.
		tmp = head;

		// Point head to next node.
		head = head->next;

		// Delete old head node.
		delete tmp;
		return true;
	}

	// Get node at a previous position.
	tmp = GetNode(i - 1);

	// If node is NULL then position does not exist or the list is empty.
	if (tmp == NULL || tmp->next == NULL)
	{
		return false;
	}

	// Get node that we want to delete.
	SLinkedListNode<T> *dNode = tmp->next;
	tmp->next = tmp->next->next;

	// If node that is being delete is tail node then point tail to the previous node.
	if (dNode == tail)
	{
		tail = tmp;
	}
	delete dNode;

	return true;
}

template <class T>
T SLinkedList<T>::GetContentAtPos(int i)
{
	// Get current node and return its contents if it is not NULL.
	SLinkedListNode<T> *tmp = GetNode(i);
	if (tmp == NULL)
	{
		return NULL;
	}

	return tmp->data;
}

template <class T>
bool SLinkedList<T>::IsInList(T value)
{
	// Point tmp to head.
	SLinkedListNode<T> *tmp = head;

	// Go through each node in the list until we reach tail.
	while (tmp != NULL)
	{
		// If valu is found return true.
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
SLinkedListNode<T>* SLinkedList<T>::GetNode(int i)
{
	if (i < 0)
	{
		return head;
	}

	int count = 0;
	SLinkedListNode<T> *tmp = head;

	while (tmp != NULL && count < i)
	{
		tmp = tmp->next;
		count++;
	}

	return tmp;
}

template <class T>
T SLinkedList<T>::GetNthElementFromTail(int n)
{
	// Return NULL if list is empty or n is out of range.
	if (IsEmpty() || n < 0)
	{
		return NULL;
	}

	// Create first pointer and point it to head.
	SLinkedListNode<T> *tmp1 = head;

	// Step through the list N times.
	for (int i = 0; i < n; i++)
	{
		// If end of the list is reached simply return NULL.
		if (tmp1->next == NULL)
		{
			return NULL;
		}

		// Keep moving first pointer to the next node.
		tmp1 = tmp1->next;
	}

	// Create second pointer.
	SLinkedListNode<T> *tmp2 = head;

	// Keep moving through the list until first pointer reaches tail.
	while (tmp1 != tail)
	{
		// Move first pointer to next node.
		tmp1 = tmp1->next;

		// Move second pointer to next node.
		tmp2 = tmp2->next;
	}

	return tmp2->data;
}

template <class T>
T SLinkedList<T>::GetNthElementFromTailRec(int n)
{
	return _GetNthElementFromTailRec(n, head);
}

template <class T>
T SLinkedList<T>::_GetNthElementFromTailRec(int n, SLinkedListNode<T> *node)
{
	// Reached the end of the list.
	if (node == NULL)
	{
		// Set position to -1 and return NULL.
		pos = -1;
		return NULL;
	}

	// Run through the list using recursive function.
	T data = _GetNthElementFromTailRec(n, node->next);
	
	// Increment position by one. 
	// Once the end of the list is reached pos will equal to -1.
	// With each function removed from the call stack pos will increment by 1.
	// If n is equals to pos then we found our element - return node data.
	pos++;
	if (pos == n)
	{
		return node->data;
	}

	return data;
}

template <class T>
T SLinkedList<T>::GetMiddleNodeContent()
{
	// If list is empty then return NULL.
	if (IsEmpty())
	{
		return NULL;
	}

	// Create two pointers and point them to head node.
	SLinkedListNode<T> *tmp1, *tmp2;
	tmp1 = tmp2 = head;

	// Go through each node until the end of the list.
	while (tmp1 != NULL)
	{
		// Check if first pointer is a tail node. If yes then return content of the second pointer.
		if (tmp1->next == NULL)
		{
			return tmp2->data;
		}

		// Move tmp1 pointer 2x times.
		tmp1 = tmp1->next->next;

		// Move tmp2 pointer 1x times.
		tmp2 = tmp2->next;
	}

	return tmp2->data;
}

template <class T>
void SLinkedList<T>::ReverseList()
{
	// If list is empty then return NULL.
	if (IsEmpty())
	{
		return;
	}

	// Create three pointers to keep track of previous current and next nodes.
	SLinkedListNode<T> *pevious, *current, *next;
	
	// Set previous and next nodes to NULL.
	pevious = next = NULL;

	// Current node is set to head node.
	current = head;

	// Tail pointer should point to old head once the list is reversed.
	tail = head;

	// Go through each node and reverse pointers one by one.
	while (current != NULL)
	{
		// Set next to next pointer of current node.
		next = current->next;

		// Point current's next pointer to previous one.
		current->next = pevious;

		// Move previous and current pointers one step.
		pevious = current;
		current = next;
	}

	// Update head pointer to the last node.
	head = pevious;
}

template <class T>
void SLinkedList<T>::Print()
{
	SLinkedListNode<T> *tmp = head;
	while (tmp != NULL)
	{
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
}