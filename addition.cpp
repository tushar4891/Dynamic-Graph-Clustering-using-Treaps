
#ifndef ADDITION
#define ADDITION

#include<bits/stdc++.h>
#include "updation.cpp"

using namespace std;

TreapNode* TreapNode :: addNode(TreapNode* &head, int key)
{
    if(head == nullptr)
    {
       return head = new TreapNode(key);
    }

    if(head->key > key)
        head->left = addNode(head->left,key);

    else
        head->right = addNode(head->right, key);

    return head;    
}

void TreapNode :: Iprint(TreapNode* head)
{
    if(head == nullptr)
        return;
    
    Iprint(head->left);
    cout<< head->key <<" ";
    Iprint(head->right);
    
}

void TreapNode :: Priprint(TreapNode* head)
{
    if(head == nullptr)
        return;
    
      cout<< head->key <<" ";
    Priprint(head->left);
  
    Priprint(head->right);
    
}
 
void TreapNode :: Poprint(TreapNode* head)
{
    if(head == nullptr)
        return;
    
    Poprint(head->left);
    
    Poprint(head->right);
    cout<< head->key <<" ";
    
}
#endif