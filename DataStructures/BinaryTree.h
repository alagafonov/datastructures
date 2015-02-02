#pragma once

#include <iostream>

using namespace std;

template <class T>
class BinaryTreeNode
{
public:
	BinaryTreeNode *left;
	BinaryTreeNode *right;
	T data;
	BinaryTreeNode(T data, BinaryTreeNode *left, BinaryTreeNode *right)
	{
		this->data = data;
		this->left = left;
		this->right = right;
	}
};

template <class T>
class BinaryTree
{
protected:
	BinaryTreeNode<T> *root;
	void Delete(BinaryTreeNode<T> *node);
	void Visit(BinaryTreeNode<T> *node);
public:
	BinaryTree();
	~BinaryTree();
	void Create(T data, BinaryTree &left, BinaryTree &right);
	void PreOrder();
	void PreOrder(BinaryTreeNode<T> *node);
	void InOrder();
	void InOrder(BinaryTreeNode<T> *node);
	void PostOrder();
	void PostOrder(BinaryTreeNode<T> *node);
	void Delete();
};

template <class T>
BinaryTree<T>::BinaryTree()
{
	root = NULL;
}

template <class T>
BinaryTree<T>::~BinaryTree()
{
	Delete();
}

template <class T>
void BinaryTree<T>::Create(T data, BinaryTree &left, BinaryTree &right)
{
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
	if (node != NULL)
	{
		Visit(node);
		PreOrder(node->left);
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
	if (node != NULL)
	{
		InOrder(node->left);
		Visit(node);
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
	if (node != NULL)
	{
		PostOrder(node->left);
		PostOrder(node->right);
		Visit(node);
	}
}

template <class T>
void BinaryTree<T>::Visit(BinaryTreeNode<T> *node)
{
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