#pragma once
#include <vector>

class Vertex;
using namespace std;

class Graph
{
public:
	Graph();
	Graph(const Graph&) = delete;
	Graph(Graph&&) = delete;
	Graph &operator=(const Graph &) = delete;
	Graph &operator=(Graph &&) = delete;

	void addVertex(Vertex &); 
	bool findVertex(int);
	vector<shared_ptr<Vertex>> getVertexes();
	void checkConnecion(Vertex &, Vertex &);
	~Graph();

	unsigned size;
private:
	vector<shared_ptr<Vertex>> vertexes;
};
