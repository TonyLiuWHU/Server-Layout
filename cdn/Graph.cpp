#include "Graph.h"

Graph::Graph() {
}

void Graph::initGraph(char* topo[MAX_EDGE_NUM]) {

	int linkNum;

	istringstream istr1(topo[0]);
	istr1 >> netNum;
	istr1 >> linkNum;
	istr1 >> consumerNum;

	istringstream istr2(topo[2]);
	istr2 >> serverCost;

	const int NetNum = netNum;
	const int ConsumerNum = consumerNum;

	this->unitPay = new AdjMatrix(NetNum, vector<int>(NetNum, INF));
	this->maxBand = new AdjMatrix(NetNum, vector<int>(NetNum, 0));
	AdjMatrix& unitPay = *this->unitPay;
	AdjMatrix& maxBand = *this->maxBand;

	int begin, end, maxB, upay;
	for (int i = 4; i < linkNum + 4; ++i) {
		istringstream istr3(topo[i]);
		istr3 >> begin;
		istr3 >> end;
		istr3 >> maxB;
		istr3 >> upay;
		unitPay[begin][end] = upay;
		unitPay[end][begin] = upay;
		maxBand[begin][end] = maxB;
		maxBand[end][begin] = maxB;
	}

	
	int requirement;
	int consum_id;
	int netNode_id;
	for (int i = linkNum + 5; i < linkNum + 5 + ConsumerNum; i++) {
		istringstream istr4(topo[i]);
		istr4 >> consum_id;
		istr4 >> netNode_id;
		istr4 >> requirement;
		consumers.push_back(CNode(consum_id, netNode_id, requirement));
	}

}