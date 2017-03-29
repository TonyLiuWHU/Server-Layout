#include <algorithm>
#include <boost/concept_check.hpp>

#include "Graph.h"

/*
* Dijkstra最短路径。
* 即，统计图中"顶点vs"到其它各个顶点的最短路径。
*
* 参数说明：
*     consumer -- 消费节点。
*     serverLocation -- 服务器节点的位置
*     prev -- 前驱顶点数组。即，prev[i]的值是"顶点vs"到"顶点i"的最短路径所经历的全部顶点中，位于"顶点i"之前的那个顶点。
*     dist -- 长度数组。即，dist[i]是"顶点vs"到"顶点i"的最短路径的长度。
*/
void dijkstra(Graph& graph, vector<int>& serverLocations, CNode& consumer, vector<int>& prev, vector<int>& dist)
{
	int k = 0;
	int min;
	int tmp;
	AdjMatrix& unitPay = *(graph.unitPay);
	AdjMatrix& maxBand = *(graph.maxBand);
	
	for (int i=0; i<maxBand.size(); i++)
	{
	  for (int j=0; j<maxBand[0].size(); j++)
	  {
		  cout << maxBand[i][j] << "\t";
	  }
	  cout << endl;
	}
	for (int i=0; i<maxBand.size(); i++)
	{
	  for (int j=0; j<maxBand[0].size(); j++)
	  {
		  cout << unitPay[i][j] << "\t";
	  }
	  cout << endl;
	}
	
	const int vexNum = unitPay.size();
	vector<int> flag(vexNum, 0);      // flag[i]=1表示"顶点vs"到"顶点i"的最短路径已成功获取。
	
						// 初始化
	for (int i = 0; i < vexNum; i++)
	{
		dist[i] = unitPay[i][consumer.netID]; // 顶点i的最短路径为"顶点vs"到"顶点i"的权。
	}

	// 对"顶点vs"自身进行初始化
	flag[consumer.netID] = 1;
	dist[consumer.netID] = 0;

	// 遍历mVexNum-1次；每次找出一个顶点的最短路径。
	for (int i = 1; i < vexNum; i++)
	{
		// 寻找当前最小的路径；
		// 即，在未获取最短路径的顶点中，找到离vs最近的顶点(k)。
		min = INF;
		for (int j = 0; j < vexNum; j++)
		{
			if (flag[j] == 0 && dist[j]<min)
			{
				min = dist[j];
				k = j;
			}
		}
		// 标记"顶点k"为已经获取到最短路径
		flag[k] = 1;

		// 修正当前最短路径和前驱顶点
		// 即，当已经"顶点k的最短路径"之后，更新"未获取最短路径的顶点的最短路径和前驱顶点"。
		for (int j = 0; j < vexNum; j++)
		{
			tmp = (unitPay[j][k] == INF ? INF : (min + unitPay[j][k]));
			if (flag[j] == 0 && (tmp  < dist[j]))
			{
				dist[j] = tmp;
				prev[j] = k;
			}
		}
		
		//如果k是服务器节点，则停止搜索，跳出循环		
		if (std::find(serverLocations.begin(), serverLocations.end(), k) != serverLocations.end())
		{
			break;
		}
		
		
	}
	
	
	// 打印dijkstra最短路径的结果
	cout << "dijkstra(" << consumer.ID << "): " << endl;
	cout << k;
	
	int demand = consumer.demand;
	//遍历从服务器节点到消费节点的整条路径，查看是否有超出带宽限制的线路
	int firstExceedNode = -1;
	int minBandNode;
	int minBand = INF;
	int start = k;
	int end = prev[start];
	while (start != consumer.netID)
	{
		if (firstExceedNode < 0 && demand > maxBand[start][end])
		{
			firstExceedNode = start;
		}
		if (maxBand[start][end] < minBand)
		{
			minBand = maxBand[start][end];
			minBandNode = start;
		}
		start = end;
		end = prev[start];
	}
	start = k;
	end = prev[start];
	while (start != consumer.netID)
	{
		maxBand[start][end] -= (demand < minBand ? demand : minBand);
		if (maxBand[start][end] <= 0)
		{
			unitPay[start][end] = INF;
		}
		start = end;
		end = prev[start];
	  
		cout << " -> " << start;
	}
	cout << "(consumer)." << endl;

	vector<int> newPrev(graph.netNum, consumer.netID);
	vector<int> newDist(graph.netNum, INF);
	vector<int> equivalentServerLocations{ firstExceedNode };
	consumer.demand -= (demand < minBand ? demand : minBand);
	if (consumer.demand <= 0)
	{
		return;
	}
	dijkstra(graph, equivalentServerLocations, consumer, newPrev, newDist);
	
//	for (int i = 0; i < vexNum; i++)
//		cout << "  shortest(" << consumer.netID << ", " << i << ")=" << dist[i] << endl;
	
}