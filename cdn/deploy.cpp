#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <iostream>
#include <string>
#include <sstream>

#include "deploy.h"
#include "core.h"
#include "Graph.h"
#include "lib_io.h"

using namespace std;

int resultNum = 0;
std::stringstream result;


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
	
	vector<int> serverLocation = initialServerLocation(graph);
	int i = 0;
	cout << "××××××××××××××××××××第" << i++ << "次尝试××××××××××××××××××××" << endl;
	while (!computeShortestPaths(graph, serverLocation))
	{
		cout << "××××××××××××××××××××第" << i++ << "次尝试××××××××××××××××××××" << endl;
		//清空输出缓存
		result.str("");
		resultNum = 0;
	}
	stringstream ss;
	ss << resultNum << endl << result.str();
	write_result(ss.str().c_str(), filename);
}
