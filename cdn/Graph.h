#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "Edge.h"
#include "SNode.h"
using namespace std;

class Graph{
private:
	int N_SNode;
	int N_CNode;
	int N_Links;
	vector<vector<int>> adjMat;

	void initGraph(const string& filename){
		ifstream file;
		file.open(filename,ios::in);
		if(!file.is_open())
			return;
		string strLine;
		getline(file,strLine);
		istringstream istr(strLine);
		istr>>N_SNode;
		istr>>N_Links;
		istr>>N_CNode;
		
		while(getline(file,strLine)){
			if(strLine.empty()){
				cout<<endl;
				continue;
			}
			vector<int> vecInt;
			int temp;
		

		}
		
	}
};
