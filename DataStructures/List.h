#pragma once

// Abstract list definition. 
template <class T>
class List {

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

	// Check if node exists in the list.
	bool IsInList(T value);

	// Clear entire list.
	void Clear();
};