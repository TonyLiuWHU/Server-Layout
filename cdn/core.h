#pragma once

#ifndef CORE_H_
#define CORE_H_

#include "Graph.h"

//初始化服务器节点位置
vector<int> initialServerLocation(Graph& graph);

//根据给定的图和服务器位置计算出完整的最短路径
bool computeShortestPaths(Graph graph, vector<int>& serverLocations);

//计算单个消费节点的最短路径，返回值为选中的服务器节点
int dijkstra(Graph& graph, vector<int>& serverLocations, CNode& consumer, vector<int>& prev, vector<int>& dist);

#endif