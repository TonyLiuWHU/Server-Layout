
#include "core.h"
#include "Graph.h"
#include "CNode.h"

using namespace std;

void computeShortestPaths(Graph& graph, vector<int>& serverLocations)
{
    //分别计算每个消费节点的最短路径
    for (int i=0; i < graph.consumerNum; i++)
    {
	vector<int> prev(graph.netNum, graph.consumers[i].netID);
	vector<int> dist(graph.netNum, INF);
	cout << "-------------Consumer " << i << "--------------------" << endl;
	dijkstra(graph, serverLocations, graph.consumers[i], prev, dist);
	
    }

}