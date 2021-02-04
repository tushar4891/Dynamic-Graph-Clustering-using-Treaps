
#ifndef MAIN
#define MAIN

#include<bits/stdc++.h>
#include "graph.h"
#include "addition.cpp"
#include "updation.cpp"
#include "neighbours.cpp"
#include "clusterDeap.h"
#include "clusterDepInsert.cpp"

using namespace std ;

void TreapNode :: nodeSearch(TreapNode* head, int no)
{
   // cout<<"head key is "<< head->key <<endl;
    //cout<<"seacrhing.... "<<endl;
    if(head->key == no)
    {
        cout<< "Neighbours of Node "<< no << " are "<< endl;
        for( auto i  = head->vec.begin(); i != head->vec.end(); i++)
        {
            cout<< *i <<" ";
        }
        cout<<endl;
        return ;
    }
    if(head->key > no)
         nodeSearch(head->left, no);
    else
         nodeSearch(head->right, no);
}

int main()
{
    TreapNode* head = nullptr;
    TreapNode t;
   clusterDeap c;

    cout<<endl;
    cout<< "Inserting nodes 1 to 26.... "<<endl<<endl;
    for( int i = 1; i <= 26; i++)
    {
        head = t.addNode(head, i);
    }    
 
    cout << "Insertion of nodes completed "<<endl<<endl;

    t.updateNode(head,1,2);
    t.updateNode(head,1,6);

    t.updateNode(head,2,3);
    t.updateNode(head,2,6);

    t.updateNode(head,3,4);
    t.updateNode(head,3,6);

    t.updateNode(head,4,7);
    t.updateNode(head,4,8);
    t.updateNode(head,4,25);

    t.updateNode(head,5,6);
    t.updateNode(head,5,10);
    t.updateNode(head,5,11);

    t.updateNode(head,6,7);
    t.updateNode(head,6,12);
    t.updateNode(head,6,13);

    t.updateNode(head,7,8);

    t.updateNode(head,8,9);

    t.updateNode(head,9,20);

    t.updateNode(head,10,11);
    t.updateNode(head,10,14);
    t.updateNode(head,10,15);
    t.updateNode(head,10,26);

    t.updateNode(head,11,12);
    t.updateNode(head,11,14);
    t.updateNode(head,11,18);

    t.updateNode(head,12,13);

    t.updateNode(head,14,15);

    t.updateNode(head,16,17);
    t.updateNode(head,16,22);

    t.updateNode(head,17,18);
    t.updateNode(head,17,19);
    t.updateNode(head,17,23);

    t.updateNode(head,18,19);

    t.updateNode(head,19,20);
    t.updateNode(head,19,22);

    t.updateNode(head,20,21);
    t.updateNode(head,20,22);

    t.updateNode(head,21,22);
    t.updateNode(head,21,23);
    t.updateNode(head,21,26);

    t.updateNode(head,23,24);
    t.updateNode(head,23,25);

    cout<<"Updation of nodes completed....  "<<endl;
   

    //cout<< "Sequence of nodes afer updation "<<endl;
    cout<< endl;


    TreapNode* root = head;

   t.findNeighbour(head);
 
  
   c.insertInCluster(root, t.MF);
}
#endif