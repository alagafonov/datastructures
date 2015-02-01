#pragma once

#include <string>

using namespace std;

class Algorithm
{
public:
	Algorithm();
	~Algorithm();
	string Factorial(int n);
	string MultiplyStrings(string n1, string n2);
	void QuickSort(int *input, int start, int size);
	void Swap(int *input, int pos1, int pos2);
	int CharToInt(char c);
	char IntToChar(int i);
	string IntToString(int n);
};

