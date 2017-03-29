#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <iostream>
#include <string>
#include <sstream>

#include "deploy.h"
#include "core.h"
#include "Graph.h"

using namespace std;

typedef int NetID;


void deploy_server(char * topo[MAX_EDGE_NUM], int line_num,char * filename)
{
	cout<<"The begin of deploy_server:"<<endl;
	
	Graph graph;
	graph.initGraph(topo);

	
	/* //test mat*******************************************
	cout<<endl<<"*************************************"<<endl;
	cout<<"UnitPay test:"<<endl;
	int NetNum = graph.netNum;
	AdjMatrix& unitPay = *(graph.unitPay);
	for(int i=0;i<NetNum;i++){
		for(int j=0;j<NetNum;j++){
			cout<<unitPay[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;

	cout<<"maxBand test:"<<endl;
	AdjMatrix& maxBand = *(graph.maxBand);
	for(int i=0;i<NetNum;i++){
		for(int j=0;j<NetNum;j++){
			cout<<maxBand[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;

	cout<<"Mat3 test:"<<endl;
	int ConsumerNum = graph.consumerNum;
	for(int j=0;j<ConsumerNum;j++){
		cout<<graph.consumers[j].ID <<"\t";
	}
	cout<<endl;
	for(int j=0;j<ConsumerNum;j++){
		cout << graph.consumers[j].demand << "\t";
	}
	cout<<endl<<"*************************************"<<endl;
	*/
	
	vector<NetID> serverLocation = initialServerLocation(graph);
	computeShortestPaths(graph, serverLocation);
}
