#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "lib_io.h"
#include "Edge.h"
#include "SNode.h"
#include "CNode.h"
#include "constants.h"
using namespace std;

typedef vector<vector<int> > AdjMatrix;

class Graph{

public:
	int N_SNode;
	int N_CNode;
	int N_Links;
	int netNum;
	int consumerNum;
	int serverCost;
// 	vector<vector<int>> unitPay;
// 	vector<vector<int>> maxBand;
	vector<vector<int> >* unitPay;
	vector<vector<int> >* maxBand;
	vector<CNode> consumers;

	Graph();
	Graph(const Graph& graph);
	void initGraph(char* topo[MAX_EDGE_NUM]);
};
