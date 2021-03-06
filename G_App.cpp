#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include "Vertex.h"
#include "Node.h"
#include "Graph.h"

int main()
{
	setlocale(LC_ALL, "Ru");

#pragma region Init

	Graph graph;
	Vertex a1;
	Vertex a2;
	Vertex a3;
	Vertex a4;
	Vertex a5;;

	a1.bind(a2);
	a2.bind(a3);
	a2.bind(a4);
	a3.bind(a5);
	a4.bind(a5);

	graph.addVertex(a1);
	graph.addVertex(a2);
	graph.addVertex(a3);
	graph.addVertex(a4);
	graph.addVertex(a5);

#pragma endregion

	a2.printLinks();
}
