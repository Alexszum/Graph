#pragma once
#include "Node.h"
#include <vector>

using namespace std;
class Vertex
{
public:
	Vertex();	

	const bool operator==(Vertex *); 
	const bool operator!=(Vertex *);

	void bind(Vertex &end);		
	void printLinks();	
	int getId();	
	unsigned getNodesSize();	
	bool findConnectedVertex(Vertex &);	

	shared_ptr<Node> getNode(int);	
	vector<shared_ptr<Node>>& getNodes(); 

	~Vertex();
private:
	static int generateID();		
	bool checkIsLinked(Vertex &);	

	vector<shared_ptr<Node>> nodes;	

	int id;
	unsigned nodesSize;

};

