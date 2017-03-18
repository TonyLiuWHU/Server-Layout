#ifndef EDGE_H_
#define EDGE_H_
#include "SNode.h"
using namespace std;

class Edge{
private:
	SNode end; 
	int band;
	int cost;
public:
	Edge(SNode end,int band,int cost){
		this->end = end;
		this->band = band;
		this->cost = cost;
	}
	
};
#endif
