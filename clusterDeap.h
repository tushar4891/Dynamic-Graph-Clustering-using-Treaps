#ifndef CLUSTER
#define CLUSTER

#include<bits/stdc++.h>
using namespace std;
#include"graph.h"

class clusterDeap
{
    public:
           int name;
           int nlinks;
           int proLinks;
           vector<int> adjacentNodes;
           clusterDeap()
           {}
           int insertInCluster(TreapNode*, vector<int>&);
           
};
#endif