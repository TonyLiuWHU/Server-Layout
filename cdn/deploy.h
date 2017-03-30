#ifndef __DEPLOY_H__
#define __DEPLOY_H__

#include <sstream>

#include "lib_io.h"

extern int resultNum;
extern std::stringstream result;

void deploy_server(char * graph[MAX_EDGE_NUM], int edge_num, char * filename);



#endif
