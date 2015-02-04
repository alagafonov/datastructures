#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Edge;

template <class T>
class Vertex
{
private:
	T data;
	vector<Edge<T> *> edges;
public:
	Vertex(const T &data)
	{
		this->data = data;
	}
	void AddEdge(Edge<T> *edge)
	{
		edges.push_back(edge);
	}
};

template <class T>
class Edge
{
private:
	Vertex<T> *from;
	Vertex<T> *to;
	int weight;
	int capacity;
	int flow;
public:
	Edge(Vertex<T> *from, Vertex<T> *to, int weight = 0, int capacity = 0, int flow = 0)
	{
		this->from = from;
		this->to = to;
		this->weight = weight;
		this->capacity = capacity;
		this->flow = flow;
	}
	int GetWeight()
	{
		return weight;
	}
};

template <class T>
class Graph
{
private:
	vector<Edge<T> *> edges;
	vector<Vertex<T> *> verticies;

public:
	Graph();
	~Graph();
	Vertex<T> &CreateVertex(const T &data);
	void CreateEdge(Vertex<T> &from, Vertex<T> &to, int weight = 0);
};

template <class T>
Graph<T>::Graph()
{
}

template <class T>
Graph<T>::~Graph()
{
	for (vector<int>::size_type i = 0; i < edges.size(); i++)
	{
		delete edges[i];
	}

	for (vector<int>::size_type i = 0; i < verticies.size(); i++)
	{
		delete verticies[i];
	}
}

template <class T>
Vertex<T> &Graph<T>::CreateVertex(const T &data)
{
	Vertex<T> *tmp = new Vertex<T>(data);
	verticies.push_back(tmp);
	return *tmp;
}

template <class T>
void Graph<T>::CreateEdge(Vertex<T> &from, Vertex<T> &to, int weight)
{
	Edge<T> *tmp = new Edge<T>(&from, &to, weight);
	from.AddEdge(tmp);
	edges.push_back(tmp);
}