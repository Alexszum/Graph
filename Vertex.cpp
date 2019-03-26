#include "pch.h"
#include "Vertex.h"
#include <iostream>

Vertex::Vertex()
{
	id = generateID();
	nodesSize = 0;
}

const bool Vertex::operator==(Vertex * v1)
{
	if (this->id == v1->id)
	{
		return true;
	}
	return false;
}

const bool Vertex::operator!=(Vertex * v1)
{
	if (this == v1)
	{
		return false;
	}
	return true;
}

void Vertex::bind(Vertex &end)
{
	if (!checkIsLinked(end))
	{
		shared_ptr<Node> node = make_shared<Node>();
		node->linkNodes(this, &end);
		nodes.push_back(node);
		end.nodes.push_back(node);
		++nodesSize;
		++end.nodesSize;
	}	
}

void Vertex::printLinks()
{
	if (nodesSize!=0)
	{
		cout << "== Data of Vertex #" << id << endl;
		for (size_t i = 0; i < nodesSize; ++i)
		{
			cout << "Node #" << i + 1 << " Main node id: " << nodes[i]->getId();
			cout << "\t connected: vertex " << nodes[i]->getFirst()->id << " , with vertex: " <<nodes[i]->getSecond()->id << endl;
		}
	}
}

int Vertex::getId()
{
	return id;
}

unsigned Vertex::getNodesSize()
{
	return nodesSize;
}

bool Vertex::findConnectedVertex(Vertex &v1)
{
	for (auto &arg : nodes)
	{
		if (v1.id == arg->getSecond()->getId())
		{
			return true;
		}
	}
	return false;
}

shared_ptr<Node> Vertex::getNode(int id)
{
	return nodes[id];
}

vector<shared_ptr<Node>>& Vertex::getNodes()
{
	return nodes;
}

Vertex::~Vertex()
{
}

int Vertex::generateID()
{
	static int ID = 0;
	ID++;
	return ID;
}

bool Vertex::checkIsLinked(Vertex &end)
{
	if (nodesSize!=0)
	{
		for (auto &node : nodes)
		{
			
			if (node->getFirst()->id == id && node->getSecond()->id == end.id || node->getSecond()->id == id && node->getFirst()->id == end.id)
			{
				cout << "ACHTUNG!! Unable to connect nodes, link is already exists" << endl;
				return true;
			}
		}
	}
	return false;
}
