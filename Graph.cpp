#include "pch.h"
#include <iostream>
#include "Graph.h"
#include "Vertex.h"


Graph::Graph()
{
	size = 0;
}


void Graph::addVertex(Vertex &vertex)
{
	vertexes.push_back(make_shared<Vertex>(vertex));
	++size;
}

bool Graph::findVertex(int id)
{
	if (!vertexes.empty())
	{
		for (auto &arg : vertexes)
		{
			if (arg->getId() == id)
			{
				return true;
			}
		}
	}
	return false;
}

vector<shared_ptr<Vertex>> Graph::getVertexes()
{
	return vertexes;
}


void Graph::checkConnecion(Vertex &start, Vertex & end)
{
	if (start.findConnectedVertex(end))
	{
		cout << "Vertex found" << endl;
	}
	else {
		cout << "Vertex missing, searching in other nodes" << endl;
		int headNodeSize = start.getNodesSize();
		for (size_t i = 0; i < headNodeSize; i++)
		{
			if (start.getNode(i)->getSecond() != nullptr &&  start != start.getNode(i)->getSecond())
			{
				checkConnecion(*start.getNode(i)->getSecond(), end);
			}
		}
	}
}

Graph::~Graph()
{
}
