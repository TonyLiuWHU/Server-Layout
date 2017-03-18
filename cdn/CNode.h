#include "SNode.h"
class CNode{
private:
	int ID;
	SNode server;
	int demand;
public:
	CNode(int id,int demand,SNode& server){
		this->ID = id;
		this->demand = demand;
		this->server = server;
	}
	int getID(){
		return this->ID;
	}
	int compareTo(CNode c){
		if(this->ID<c.getID())
		  return -1;
		else if(this->ID>c.getID())
		  return 1;
		return 0;
	}
};
