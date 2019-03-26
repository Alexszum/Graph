#include "pch.h"
#include "Node.h"
class Vertex;

Node::Node()
{
	id = generateID();
	end = nullptr;
}

void Node::linkNodes(Vertex *begin, Vertex *end)
{
	this->begin = std::move(begin);
	this->end = std::move(end);
}


Vertex * Node::getFirst()
{
	return begin;
}

Vertex * Node::getSecond()
{
	return end;
}

int Node::getId()
{
	return id;
}

Node::~Node()
{
	begin = nullptr;	
	end = nullptr;
}

int Node::generateID()
{
	static int NID = 0;
	++NID;
	return NID;
}
