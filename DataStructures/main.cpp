#include <iostream>
#include "SLinkedList.h"
#include "DLinkedList.h"
#include "CLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "Algorithm.h"
#include "HashTable.h"
#include "BinaryTree.h"
#include "BinarySearchTree.h"
#include "Graph.h"
#include "MinHeap.h"

using namespace std;

int main(int argc, char *argv[])
{
	// Singly linked list.
	//SLinkedList<int> lList;
	//lList.AppendToTail(4);
	//lList.AppendToTail(3);
	//lList.AppendToTail(2);
	//lList.AppendToTail(1);
	//lList.ReverseList();
	//cout << lList.GetNthElementFromTail(3) << endl;
	//cout << lList.GetNthElementFromTailRec(1) << endl;
	//cout << lList.GetMiddleNodeContent() << endl;
	//lList.InsertAtPos(0, 9);
	//lList.DeleteAtPos(2);
	//lList.AppendToTail(101);
	//cout << lList.GetContentAtPos(100) << endl;
	//cout << lList.IsInList(22) << endl;
	//lList.Print();

	// Doubly linked list.
	//DLinkedList<int> dList;
	//dList.AppendToHead(11);
	//dList.AppendToTail(1);
	//dList.AppendToTail(3);
	//dList.DeleteTail();
	//dList.DeleteTail();
	//dList.AppendToHead(24);
	//dList.AppendToTail(23);
	//cout << dList.IsInList(24) << endl;
	//dList.Print();
	//dList.PrintBackwards();

	// Circular linked list.
	//CLinkedList<int> cList;
	//cList.AppendToTail(11);
	//cList.AppendToTail(1);
	//cList.AppendToTail(3);
	//cout << cList.GetCurrentNode() << endl;
	//cout << cList.GetCurrentNode() << endl;
	//cout << cList.GetCurrentNode() << endl;
	//cList.Print();

	// Stack.
	//Stack<int> stack;
	//stack.Push(10);
	//stack.Push(12);
	//stack.Push(14);
	//stack.Push(15);
	//cout << stack.Pop() << endl;
	//cout << stack.GetTop() << endl;
	//cout << stack.IsEmpty() << endl;
	//stack.Print();

	// Queue.
	//Queue<int> queue;
	//queue.EnQueue(10);
	//queue.EnQueue(12);
	//queue.EnQueue(14);
	//queue.EnQueue(15);
	//cout << queue.DeQueue() << endl;
	//cout << queue.DeQueue() << endl;
	//cout << queue.GetFirstNode() << endl;
	//cout << queue.IsEmpty() << endl;
	//queue.Print();

	// Various algorithms.
	//Algorithm alg;
	//cout << alg.Hancart("test", "not tes found") << endl;
	//cout << "0! = " << alg.Factorial(0) << endl << endl;
	//cout << "10! = " << alg.Factorial(10) << endl << endl;
	//cout << "12! = " << alg.Factorial(12) << endl << endl;
	//cout << "13! = " << alg.Factorial(13) << endl << endl;
	//cout << "1000! = " << alg.Factorial(100) << endl;
	//int data[12] = { 5, 6, 3, 4, 1, 69, 23, 5, 1, 5, 3456, 3 };
	//alg.QuickSort(data, 0, 11);
	//alg.BubbleSort(data, 12);
	//int data[5] = { 5, 6, 10, 23, 98 };
	//cout << alg.BinarySearch(data, 98, 0, 4) << endl;
	//for (int i = 0; i < 12; i++)
	//{
	//	cout << data[i] << " ";
	//}

	// Hash table.
	//HashTable<int, string> hs;
	//hs.Insert(1, "A");
	//hs.Insert(2, "B");
	//hs.Insert(10, "C");
	//hs.Insert(1937, "D");
	//hs.Insert(1937, "E");
	//const string *tmp = hs.Retrieve(10);
	//if (tmp != nullptr)
	//{
	//	cout << *tmp << endl;
	//}
	//hs.Print();

	// Binary tree.
	//BinaryTree<string> rt, t1, t2, t3, t4, t5, t6, t7, t8, t9, empty;
	//t9.Create("C", empty, empty);
	//t8.Create("E", empty, empty);
	//t7.Create("H", empty, empty);
	//t2.Create("A", empty, empty);
	//t6.Create("D", t9, t8);
	//t5.Create("I", t7, empty);
	//t4.Create("B", t2, t6);
	//t3.Create("G", empty, t5);
	//rt.Create("F", t4, t3);
	//rt.PostOrder();

	// Binary search tree.
	//BinarySearchTree<int> bst;
	//bst.Insert(10);
	//bst.Insert(3);
	//bst.Insert(20);
	//bst.Insert(12);
	//bst.PreOrder();

	// Graph.
	//Graph<int> g;
	//Vertex<int> &v1 = g.CreateVertex(10);
	//Vertex<int> &v2 = g.CreateVertex(20);
	//g.CreateEdge(v1, v2);

	// Min heap.
	MinHeap mh(10);
	mh.Insert(10);
	mh.Insert(11);
	mh.Insert(12);
	mh.Insert(33);
	mh.Insert(5);
	mh.Insert(5);
	mh.Print();

	std::getchar();
	return 0;
}