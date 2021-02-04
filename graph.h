
#ifndef GRAPH
#define GRAPH
#include<bits/stdc++.h>
//#include "main.cpp"
using namespace std;

// header of Treap data structure
class TreapNode
{
    public:
            int key;
            int priority;
            TreapNode* left, *right;
            vector<int> vec;
            //int *vectorAddress = vec.data();
            // constructor of TrepNode
            vector<vector<int> > neighborNode;
            TreapNode(int key)
            {
                this->priority = 0;
                this->key = key;
                this->left  = nullptr;
                this->right = nullptr;
            }
            
            TreapNode()
            {}
            vector<int> MF;
            TreapNode* addNode(TreapNode*&,int);
            void updateNode(TreapNode*&,int,int);
            void Iprint(TreapNode*);
            void Priprint(TreapNode*);
            void Poprint(TreapNode*);
            void nodeSearch(TreapNode*, int);
            void findNeighbour(TreapNode*);
};

#endif

