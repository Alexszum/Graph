#pragma once
#include <memory>
using namespace std;
class Vertex;

class Node
{
public:
	Node();
	Node(const Node&) = delete;
	Node(Node&&) = delete;
	Node &operator=(const Node &) = delete;
	Node &operator=(Node &&) = delete;

	void linkNodes(Vertex *, Vertex *); 
	Vertex* getFirst();	
	Vertex* getSecond();	
	int getId();

	~Node();
private:
	int id;
	static int generateID();	
	Vertex *begin = nullptr;	
	Vertex *end = nullptr;	
};

