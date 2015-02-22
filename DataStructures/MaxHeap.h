#include <iostream>
#include <algorithm>

using namespace std;

class MaxHeap
{
private:
	int *data;
	int size;
	int cSize;
	int GetParentIndex(int index);
	int GetLeftChildIndex(int index);
	int GetRightChildIndex(int index);
	void SiftUp(int index);
	void SiftDown(int index, int depth);
public:
	MaxHeap(int size);
	MaxHeap(int *arr, int size);
	~MaxHeap();
	bool Insert(int index);
	void Heapify();
	void HeapSort();
	void Print();
};

MaxHeap::MaxHeap(int size)
{
	cSize = 0;
	this->size = size;
	data = new int[size];
}

MaxHeap::MaxHeap(int *arr, int size)
{
	this->size = cSize = size;
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = arr[i];
	}

	Heapify();
}

MaxHeap::~MaxHeap()
{
	delete[] data;
}

void MaxHeap::HeapSort()
{
	// Make sure heap is not empty.
	if (cSize > 0)
	{
		for (int i = cSize - 1; i > 0; i--)
		{
			swap(data[0], data[i]);
			SiftDown(0, i);
		}
	}
}

void MaxHeap::Heapify()
{
	for (int i = cSize / 2 - 1; i >= 0; i--)
	{
		SiftDown(i, cSize);
	}
}

bool MaxHeap::Insert(int value)
{
	// Check if the heap is full.
	if (cSize == size)
	{
		return false;
	}

	data[cSize] = value;
	SiftUp(cSize);
	cSize++;

	return true;
}

int MaxHeap::GetParentIndex(int index)
{
	return (index - 1) / 2;
}

int MaxHeap::GetLeftChildIndex(int index)
{
	return index * 2 + 1;
}

int MaxHeap::GetRightChildIndex(int index)
{
	return index * 2 + 2;
}

void MaxHeap::SiftUp(int index)
{
	// Parent index.
	int parent;

	// Make sure this is not the first element.
	if (index != 0)
	{
		// Get parent index.
		parent = GetParentIndex(index);

		// If parent value is bigger than new value then we swap them.
		if (data[parent] < data[index])
		{
			swap(data[parent], data[index]);

			// Continue sifting up.
			SiftUp(parent);
		}
	}
}

void MaxHeap::SiftDown(int index, int depth)
{
	int lc = GetLeftChildIndex(index);
	int tmp = data[index];

	while (lc < depth)
	{
		// If there is right child and it is smaller than left child then we use right child index.
		if (lc + 1 < depth && data[lc] < data[lc + 1])
		{
			lc++;
		}

		if (tmp < data[lc])
		{
			data[index] = data[lc];
			index = lc;
			lc = GetLeftChildIndex(lc);
		}
		else
		{
			break;
		}
	}
	data[index] = tmp;
}

void MaxHeap::Print()
{
	for (int i = 0; i < cSize; i++)
	{
		cout << data[i] << " ";
	}
}