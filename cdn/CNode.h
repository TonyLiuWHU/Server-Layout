#pragma once

#ifndef CNODE_H_
#define CNODE_H_

class CNode{

public:
	int ID;
	int netID;
	int demand;
	
	CNode(const CNode& cnode) : ID(cnode.ID), netID(cnode.netID), demand(cnode.demand) {}

	CNode(int id, int netID, int demand) : ID(id), netID(netID), demand(demand) {}
	
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

#endif