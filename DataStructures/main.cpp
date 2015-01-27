#include <iostream>
#include "SLinkedList.h"
#include "DLinkedList.h"
#include "CLinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "Algorithm.h"

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

	// Stack.
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

	// Factorial.
	Algorithm alg;
	cout << "0! = " << alg.Factorial(0) << endl << endl;
	cout << "10! = " << alg.Factorial(10) << endl << endl;
	cout << "12! = " << alg.Factorial(12) << endl << endl;
	cout << "13! = " << alg.Factorial(13) << endl << endl;
	cout << "1000! = " << alg.Factorial(100) << endl;

	std::getchar();
	return 0;
}