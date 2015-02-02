#include <iostream>

using namespace std;

template <class K, class E>
class HashTableNode
{
public:
	K index;
	E data;
	HashTableNode()
	{
	}
	HashTableNode(K ix, E dt)
	{
		index = ix;
		data = dt;
	}
};

template <class K, class E>
class HashTable
{
private:
	int tSize;
	int cSize;
	HashTableNode<K, E> **items;
	int GetHash(int index) const;
	int GetHash(string index) const;
	int LinearAddress(int i) const;

public:
	HashTable(int size = 32);
	~HashTable();
	bool Insert(K index, E data);
	const E *Retrieve(K index);
	void Print();
};

template <class K, class E>
HashTable<K, E>::HashTable(int size)
{
	tSize = size;
	items = new HashTableNode<K, E>*[tSize];
	for (int i = 0; i < tSize; i++)
	{
		items[i] = nullptr;
	}
}

template <class K, class E>
HashTable<K, E>::~HashTable()
{
	for (int i = 0; i < tSize; i++)
	{
		delete items[i];
		items[i] = NULL;
	}

	delete [] items;
}

template <class K, class E>
int HashTable<K, E>::GetHash(int index) const
{
	return index % (tSize - 1);
}

template <class K, class E>
int HashTable<K, E>::LinearAddress(int i) const
{
	if (++i >= tSize)
	{
		return 0;
	}

	return i;
}

template <class K, class E>
bool HashTable<K, E>::Insert(K index, E data)
{
	// Check if table is full.
	if (tSize == cSize)
	{
		return false;
	}

	// Generate hash based on index.
	int hash = GetHash(index);

	// Find an empty spot for the new item.
	while (items[hash] != nullptr)
	{
		// This index is already present in the table.
		if (items[hash]->index == index)
		{
			// Overwrite the data for the index.
			items[hash]->data = data;
			return true;
		}

		// Collision resolution using open addressing method (linear function).
		hash = LinearAddress(hash);
	}

	// Add new item.
	items[hash] = new HashTableNode<K, E>(index, data);

	// Keep track of the size of the table.
	cSize++;

	return true;
}

template <class K, class E>
const E *HashTable<K, E>::Retrieve(K index)
{
	// Generate hash based on index.
	int hash = GetHash(index);
	int bHash = hash;

	while (true)
	{
		// If item does not exist at this index return NULL.
		if (items[hash] == nullptr)
		{
			return nullptr;
		}

		// Found our index, return data.
		if (items[hash]->index == index)
		{
			return &items[hash]->data;
		}

		// Get next address (linear function).
		hash = LinearAddress(hash);

		if (bHash == hash)
		{
			return nullptr;
		}
	}

	return nullptr;
}

template <class K, class E>
void HashTable<K, E>::Print()
{
	for (int i = 0; i < tSize; i++)
	{
		if (items[i] != nullptr)
		{
			cout << "Pos " << i << " = " << items[i]->data << endl;
		}
		else
		{
			cout << "Pos " << i << " = NULL" << endl;
		}
		
	}
}


