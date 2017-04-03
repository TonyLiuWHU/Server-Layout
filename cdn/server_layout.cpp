#include <map>
#include <algorithm>

#include "Graph.h"

using namespace std;

struct CompareByTotalBand {
	bool operator()(const pair<int, int>& net1, const pair<int, int>& net2)
	{
		return net1.second > net2.second;
	}
};

vector<int> initialServerLocation(Graph& graph)
{
	AdjMatrix& maxBand = *(graph.maxBand);
	vector<pair<int, int>> totalBands;
	for (int i=0; i < maxBand.size(); i++)
	{
		int totalBand = 0;
		for (int j=0; j <maxBand.size(); j++)
		{
			totalBand += maxBand[i][j];
		}
		totalBands.push_back(pair<int, int>(i, totalBand));
	}
	sort(totalBands.begin(), totalBands.end(), CompareByTotalBand());
	for (vector<pair<int, int>>::iterator it = totalBands.begin(); it != totalBands.end(); it++)
	{
		cout << it->first << "\t" << it->second << endl;
	}
	
	vector<int> serverLocation(maxBand.size() / 10);
	for (int i=0; i < maxBand.size() / 10; i++)
	{
		serverLocation[i] = totalBands[i].first;
	}
	for (int i=0; i < serverLocation.size(); i++)
	{
		cout << serverLocation[i] << " ";
	}

//  return vector<int>{ 0, 1, 2, 17, 13, 33, 15 };
//  return vector<int>{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
//  return vector<int>{ 0, 1 };
	return serverLocation;
}