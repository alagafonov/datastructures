#pragma once

#include <iostream>

using namespace std;

// Binary tree node class.
// Stores node contents and the pointer to the left and right nodes.
template <class T>
class BinaryTreeNode
{
public:
	BinaryTreeNode *left;
	BinaryTreeNode *right;
	T data;
	BinaryTreeNode(const T &data, BinaryTreeNode *left, BinaryTreeNode *right)
	{
		this->data = data;
		this->left = left;
		this->right = right;
	}
};

// Binary tree class.
template <class T>
class BinaryTree
{
protected:
	BinaryTreeNode<T> *root;

	// Delete entire tree.
	void Delete(BinaryTreeNode<T> *node);

	// Visit a node.
	void Visit(BinaryTreeNode<T> *node);
public:
	BinaryTree();
	~BinaryTree();

	// Creates new tree.
	void Create(const T &data, BinaryTree &left, BinaryTree &right);

	// Preorder traversal using recursion - wrapper method.
	void PreOrder();

	// Preorder traversal using recursion.
	void PreOrder(BinaryTreeNode<T> *node);
	
	// Inorder traversal using recursion - wrapper method.
	void InOrder();
	
	// Inorder traversal using recursion.
	void InOrder(BinaryTreeNode<T> *node);
	
	// Postorder traversal using recursion - wrapper method.
	void PostOrder();
	
	// Postorder traversal using recursion.
	void PostOrder(BinaryTreeNode<T> *node);

	// Delete wrapper method.
	void Delete();
};

template <class T>
BinaryTree<T>::BinaryTree()
{
	// Create empty tree with root pointing to NULL.
	root = NULL;
}

template <class T>
BinaryTree<T>::~BinaryTree()
{
	// Delete tree.
	Delete();
}

template <class T>
void BinaryTree<T>::Create(const T &data, BinaryTree &left, BinaryTree &right)
{
	// Create new tree.
	root = new BinaryTreeNode<T>(data, left.root, right.root);
}

template <class T>
void BinaryTree<T>::PreOrder()
{
	PreOrder(root);
}

template <class T>
void BinaryTree<T>::PreOrder(BinaryTreeNode<T> *node)
{
	// Preorder traversal using recursion.
	if (node != NULL)
	{
		// Visit node first.
		Visit(node);

		// Go to left node.
		PreOrder(node->left);

		// Go to right node.
		PreOrder(node->right);
	}
}

template <class T>
void BinaryTree<T>::InOrder()
{
	InOrder(root);
}

template <class T>
void BinaryTree<T>::InOrder(BinaryTreeNode<T> *node)
{
	// Inorder traversal using recursion.
	if (node != NULL)
	{
		// Go to left node.
		InOrder(node->left);

		// Visit node.
		Visit(node);

		// Go to right node.
		InOrder(node->right);
	}
}

template <class T>
void BinaryTree<T>::PostOrder()
{
	PostOrder(root);
}

template <class T>
void BinaryTree<T>::PostOrder(BinaryTreeNode<T> *node)
{
	// Postorder traversal using recursion.
	if (node != NULL)
	{
		// Go to left node.
		PostOrder(node->left);

		// Go to right node.
		PostOrder(node->right);

		// Visit node.
		Visit(node);
	}
}

template <class T>
void BinaryTree<T>::Visit(BinaryTreeNode<T> *node)
{
	// This function just prints contents of the node on the screen.
	cout << node->data << " ";
}

template <class T>
void BinaryTree<T>::Delete()
{
	Delete(root);
}

template <class T>
void BinaryTree<T>::Delete(BinaryTreeNode<T> *node)
{
	if (node != NULL)
	{
		delete node;
		node = NULL;
	}
}