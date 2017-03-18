#ifndef SNODE_H_
#define SNODE_H_

#include <vector>
#include <list>
#include <iostream>
using namespace std;

class Edge;

class SNode{
private:
	int ID;
	list<Edge> edges;
	SNode *previous;
	bool isVisited;
public:
	SNode(int id){
		ID = id;
		previous = NULL;
		isVisited = false;
	}
	SNode(){}
	int getID(){
		return ID;
	}
	int compareTo(SNode s){
		if(this->ID<s.getID())
		  return -1;
		else if(this->ID>s.getID()){
			return 1;
		}
		return 0;
	}
};

#endif

