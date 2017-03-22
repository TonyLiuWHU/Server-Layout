#include "deploy.h"
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


void deploy_server(char * topo[MAX_EDGE_NUM], int line_num,char * filename)
{
	int consumerNum;
	int netNum;
	int linkNum;
	int serverCost;
	cout<<"The begin of deploy_server:"<<endl;
	
	istringstream istr1(topo[0]);
	istr1>>netNum;
	istr1>>linkNum;
	istr1>>consumerNum;
	
	istringstream istr2(topo[1]);
	istr2>>serverCost;
	
	const int NetNum = netNum;
	const int ConsumerNum = consumerNum;
	int unitPay[NetNum][NetNum];
	int maxBand[NetNum][NetNum];

	for(int i=0;i<NetNum;i++){
		for(int j=0;j<NetNum;j++){
			unitPay[i][j] = 100000;
		}
	}

	for(int i=0;i<NetNum;i++){
		for(int j=0;j<NetNum;j++){
			maxBand[i][j] = 0;
		}
	}

	int begin,end,maxB,upay;
	for(int i = 2; i < linkNum+2-1; ++i){
		istringstream istr3(topo[i]);
		istr3>>begin;
		istr3>>end;
		istr3>>maxB;
		istr3>>upay;
		unitPay[begin][end] = upay;
		unitPay[end][begin] = upay;
		maxBand[begin][end] = maxB;
		maxBand[end][begin] = maxB;
	//	while(*ch != '\0'){
	//	    cout<<*ch;
	//	    ch++;
	//	}
	}

	int consum_net[2][ConsumerNum];
	int requirement;
	int consum_id;
	int netNode_id;
	for(int i=linkNum+2;i<line_num;++i){
		istringstream istr4(topo[i]);
		istr4>>consum_id;
		istr4>>netNode_id;
		istr4>>requirement;
		consum_net[0][consum_id] = netNode_id;
		consum_net[1][consum_id] = requirement;
	}

	//test mat*******************************************
	
	cout<<endl<<"*************************************"<<endl;
	cout<<"UnitPay test:"<<endl;
	for(int i=0;i<NetNum;i++){
		for(int j=0;j<NetNum;j++){
			cout<<unitPay[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<"maxBand test:"<<endl;

	for(int i=0;i<NetNum;i++){
		for(int j=0;j<NetNum;j++){
			cout<<maxBand[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;

	cout<<"Mat3 test:"<<endl;

	for(int i=0;i<2;i++){
		for(int j=0;j<ConsumerNum;j++){
			cout<<consum_net[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl<<"*************************************"<<endl;
    //int consumerNum = 0;
    //char *c;
    //int spaceCount = 0;
    //
    //c = topo[0];
    //
    //while (*c != '\0' && *c != '\n' && *c != '\r') 
    //{
    //    if (*c == ' ') 
    //    {
    //        c++;
    //        spaceCount++;
    //        continue;
    //    }
    //    if (spaceCount == 2) 
    //    {
    //        consumerNum = *c - '0' + consumerNum * 10;
    //    }
    //    c++;
    //}
    //
    //string res;
    //char a[20];
    //sprintf(a, "%d\n\n",consumerNum);
    //res = a;
    //int netnode, need;
    //
    //for (int i = 1; i < consumerNum+1; i++)
    //{
    //    c = topo[line_num-i];
    //    netnode = need = spaceCount = 0;
    //    while (*c != '\0' && *c != '\n' && *c != '\r') 
    //    {
    //        if (*c == ' ') 
    //        {
    //            c++;
    //            spaceCount++;
    //            continue;
    //        }
    //        if (spaceCount == 1)
    //        {
    //            netnode = *c - '0' + netnode * 10;
    //        }
    //        else if (spaceCount == 2) 
    //        {
    //            need = *c - '0' + need * 10;
    //        }
    //        c++;
    //    }
    //    sprintf(a, "%d %d %d",netnode,consumerNum-i,need);
    //    res += a;
    //    if (i != consumerNum) 
    //    {
    //        res += "\n";
    //    }
    //}
    //
    //char * topo_file = (char *)res.c_str();
    //write_result(topo_file, filename);
}
