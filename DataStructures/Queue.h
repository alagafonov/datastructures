#include <iostream> 

using namespace std;

// Queue node class.
template <class T>
class QueueNode
{
public:
	T data;
	QueueNode *next;
	QueueNode(const T info, QueueNode *nextValue = NULL)
	{
		data = info;
		next = nextValue;
	}
	QueueNode(QueueNode *nextValue = NULL)
	{
		next = nextValue;
	}
};

// Queue class.
template <class T>
class Queue
{
private:
	QueueNode<T> *front;
	QueueNode<T> *rear;
	int size;

public:
	Queue();
	~Queue();

	// Check if queue is empty.
	bool IsEmpty();

	// Clear the queue.
	void Clear();

	// Add an item to the end of the queue.
	bool EnQueue(T item);

	// Get an item from the front of the queue.
	T DeQueue();

	// Get an item from the front of the queue without removing it.
	T GetFirstNode();

	// Print contents of the queue.
	void Print();
};

template <class T>
Queue<T>::Queue()
{
	// Create empty queue with front and rear pointing to NULL.
	front = rear = NULL;
}

template <class T>
Queue<T>::~Queue()
{
	Clear();
}

template <class T>
bool Queue<T>::IsEmpty()
{
	// If front is NULL then the queue is empty.
	return front == NULL;
}

template <class T>
void Queue<T>::Clear()
{
	QueueNode<T> *tmp;

	// Go through each node until the end of the queue.
	while (front != NULL)
	{
		// Point tmp to next node.
		tmp = front->next;

		// Delete current node.
		delete front;

		// Point front to next node.
		front = tmp;
	}
}

template <class T>
bool Queue<T>::EnQueue(T value)
{
	// Create new node.
	QueueNode<T> *node = new QueueNode<T>(value);
	size++;

	// If queue is empty then point both front and rear to the new node.
	if (IsEmpty())
	{
		front = rear = node;
		return true;
	}

	// Add node to the end of the queue and repoint rear to the new node.
	rear->next = node;
	rear = node;

	return true;
}

template <class T>
T Queue<T>::DeQueue()
{
	// If queue is empty return NULL.
	if (IsEmpty())
	{
		return NULL;
	}

	// Save value from top node.
	T value = front->data;

	// Point tmp to front.
	QueueNode<T> *tmp = front;

	// Repoint front to the second node in the queue.
	front = front->next;

	// Remove first node.
	delete tmp;

	// Update queue size.
	size--;

	return value;
}

template <class T>
T Queue<T>::GetFirstNode()
{
	// If queue is empty return NULL.
	if (IsEmpty())
	{
		return NULL;
	}

	return front->data;
}

template <class T>
void Queue<T>::Print()
{
	QueueNode<T> *tmp = front;
	while (tmp != NULL)
	{
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
}