#include <iostream>
#include <algorithm>

using namespace std;

class MinHeap
{
private:
	int *data;
	int size;
	int cSize;
	int GetParentIndex(int index);
	void SiftUp(int index);
public:
	MinHeap(int size);
	~MinHeap();
	bool Insert(int index);
	void Print();
};

MinHeap::MinHeap(int size)
{
	cSize = 0;
	this->size = size;
	data = new int[size];
}

MinHeap::~MinHeap()
{
	delete[] data;
}

bool MinHeap::Insert(int value)
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

int MinHeap::GetParentIndex(int index)
{
	return (index - 1) / 2;
}

void MinHeap::SiftUp(int index)
{
	// Parent index.
	int parent;

	// Make sure this is not the first element.
	if (index != 0)
	{
		// Get parent index.
		parent = GetParentIndex(index);

		// If parent value is bigger than new value then we swap them.
		if (data[parent] > data[index])
		{
			swap(data[parent], data[index]);

			// Continue sifting up.
			SiftUp(parent);
		}
	}
}

void MinHeap::Print()
{
	for (int i = 0; i < cSize; i++)
	{
		cout << data[i] << " ";
	}
}