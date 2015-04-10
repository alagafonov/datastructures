#include <iostream>
#include "BinaryTree.h"

using namespace std;

// Binary search tree class inherits fron binary tree class.
template <class T>
class BinarySearchTree : public BinaryTree<T>
{
public:
	BinarySearchTree();
	~BinarySearchTree();

	// Insert new node into BST.
	void Insert(const T &data);
};

template <class T>
BinarySearchTree<T>::BinarySearchTree()
{
	BinaryTree();
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
	if (root != NULL)
	{
		Delete(root->left);
		Delete(root->right);
	}
}

template <class T>
void BinarySearchTree<T>::Insert(const T &data)
{
	// Indicates which child it is, left or right.
	char direction = 0;
	
	// Create two pointers and point both to root node.
	BinaryTreeNode<T> *tmp = root, *node = root;
	
	// Look for empty space to put our new node into.
	while (tmp != NULL)
	{
		// Point node to tmp.
		node = tmp;

		// If new data variable is smaller than current node's data - move to left.
		if (tmp->data > data)
		{
			tmp = tmp->left;
			direction = 1;
		}
		// Else move to right.
		else
		{
			tmp = tmp->right;
			direction = 2;
		}
	}
	
	// Tree is empty create root node.
	if (direction == 0)
	{
		root = new BinaryTreeNode<T>(data, NULL, NULL);
	}

	// Add new node to left.
	else if (direction == 1)
	{
		node->left = new BinaryTreeNode<T>(data, NULL, NULL);
	}

	// Add new node to right.
	else if (direction == 2)
	{
		node->right = new BinaryTreeNode<T>(data, NULL, NULL);
	}
}
