#include <iostream>
#include "BinaryTree.h"

using namespace std;

template <class T>
class BinarySearchTree : public BinaryTree<T>
{
protected:
	void Delete(BinaryTreeNode<T> *node);
public:
	BinarySearchTree();
	~BinarySearchTree();
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
}

template <class T>
void BinarySearchTree<T>::Insert(const T &data)
{
	char direction = 0;
	BinaryTreeNode<T> *tmp = root, *node = root;
	while (tmp != NULL)
	{
		node = tmp;

		// New data variable is smaller than current node's data - move to left.
		if (tmp->data < data)
		{
			tmp = tmp->left;
			direction = 1;
		}
		else
		{
			tmp = tmp->right;
			direction = 2;
		}
	}

	if (direction == 0)
	{
		root = new BinaryTreeNode<T>(data, NULL, NULL);
	}
	else if (direction == 1)
	{
		node->left = new BinaryTreeNode<T>(data, NULL, NULL);
	}
	else if (direction == 2)
	{
		node->right = new BinaryTreeNode<T>(data, NULL, NULL);
	}
}

template <class T>
void BinarySearchTree<T>::Delete(BinaryTreeNode<T> *node)
{
	if (node != NULL)
	{
		Delete(node->left);
		Delete(node->right);
		delete node;
	}
}