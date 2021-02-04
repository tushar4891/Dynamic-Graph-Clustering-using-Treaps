
#ifndef CLUSTERDEP
#define CLUSTERDEP

#include<bits/stdc++.h>
#include "clusterDeap.h"
#include "neighbours.cpp"

using namespace std;

void Iprint(TreapNode* head)
{
    if(head == nullptr)
        return;
    
    Iprint(head->left);
    cout<< head->key <<" ";
    Iprint(head->right);
    
}

void Priprint(TreapNode* head)
{
    if(head == nullptr)
        return;
    
      cout<< head->key <<" ";
    Priprint(head->left);
  
    Priprint(head->right);
    
}

void  Poprint(TreapNode* head)
{
    if(head == nullptr)
        return;
    
    Poprint(head->left);
    
    Poprint(head->right);
    cout<< head->key <<" " ;
    
}


TreapNode* searchInCluster(TreapNode* head, int j)
{
    if(head->key == j)
        return head;
    
    if(head->key < j )
         searchInCluster(head->right, j);
    else
         searchInCluster(head->left, j);
    
}

clusterDeap* getNode(TreapNode* head, int j)
{
    clusterDeap *c = new clusterDeap();
    c->name = j;

    //cout<<"j = "<< j <<endl;
    TreapNode* add = searchInCluster(head, j);
    //cout<< "add->key = "<< add->key <<endl;
   // cout <<"search Completed "<<endl;

   // cout<< "add->vec.size() "<< add->vec.size() <<endl;
    for(int i = 0 ; i < add->vec.size(); i++)
    {
       // cout<<" add->vec[i]  " << add->vec[i] <<endl;
        c->adjacentNodes.push_back(add->vec[i]);
    }
    return c;
}

int clusterDeap :: insertInCluster(TreapNode* head, vector<int>& MF)
{
    TreapNode* root = head;
    //cout<< "root->key = "<< root->key <<endl;
    //cout<<"root address = "<< root <<endl;
    //cout<<"root->left->key = "<< root->left->key <<endl;

    /*cout<<" Traversing of nodes "<<endl;
    Priprint(root);
    cout<<endl;
    Iprint(root);
    cout<<endl;
    Poprint(root);
    cout<<endl;
    cout<<endl; 
  */
    vector< vector<clusterDeap *> > cluster;
    int j = 1;
    clusterDeap *clusterD;
    int k = 1;
   // cout<<"k "<<endl;
    vector<clusterDeap *> vec;

    for( int i = 0; i < 6; i++, k++)
    {
       /// cout<<"i "<< i << endl;
        while(MF[j] == k )
        {
           // cout<<"j's value "<< j << endl;
            clusterD = getNode(root, j);
          //  cout<<"Inserted key is  "<< clusterD->name << endl;
            vec.push_back(clusterD); 
            j++;
        }  
      //  cout<<"end of j "<< j << endl;
     //   cout<<"k's value "<< k <<endl;
        cluster.push_back(vec); 
        vec.clear();
       // cout<<"done "<<endl;  
    }

cout<<"all the adjacent nodes "<<endl;
    for( int i = 0; i < 6; i++)
    {
        for( int j = 0 ; j < cluster[i].size(); j++)
        {
            for(int k = 0 ; k < cluster[i][j]->adjacentNodes.size(); k++)
            {
                cout<< cluster[i][j]->adjacentNodes[k] <<"  ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
/*
    cout<<" End of Traversing of nodes "<<endl;
    Priprint(head);
    cout<<endl;
    Iprint(head);
    cout<<endl;
    Poprint(head);
    cout<<endl;
    cout<<endl; 
*/
}
#endif