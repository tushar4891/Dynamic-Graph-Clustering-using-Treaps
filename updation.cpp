#ifndef UPDATION
#define UPDATION

#include<bits/stdc++.h>
#include "graph.h"
#include "addition.cpp"
#include "main.cpp"

using namespace std;

 pair<TreapNode*, TreapNode*> myPair;


void iprint(TreapNode* head)
{
    if(head == nullptr)
        return;
    
    iprint(head->left);
    cout<< head->key <<" ";
    iprint(head->right);
    
}

void priprint(TreapNode* head)
{
    if(head == nullptr)
        return;
    
      cout<< head->key <<" ";
    priprint(head->left);
  
    priprint(head->right);
    
}

void  poprint(TreapNode* head)
{
    if(head == nullptr)
        return;
    
    poprint(head->left);
    
    poprint(head->right);
    cout<< head->key <<" ";
    
}

pair<TreapNode*, TreapNode*> searchNode(TreapNode* &head, int source, TreapNode* firstAdd, TreapNode* secondAdd)
{
    if( head->key == source)
    {
        if(!firstAdd)
        {
             myPair.first =  head;
             myPair.second = head;
             return myPair;
        }

        myPair.first = firstAdd;
        myPair.second = head;
        return myPair;
    }   
    
    if(head->key > source)
         searchNode(head->left, source, head, head->left);
    else
         searchNode(head->right, source, head, head->right);
}

TreapNode* updateNonRootNode(TreapNode* head, TreapNode* parent, TreapNode* child)
{
    //child is left to the parent
    if(parent->left == child)
    {
        // When both child are present.
        if(child->left && child->right)
        {
            if((child->left->priority == child->right->priority) && (child->priority > child->left->priority))
            {
                TreapNode* temp = child->right;

                parent->left = temp;

                child->right = temp->left;

                temp->left = child;
                
                return updateNonRootNode(head,parent->left, child);
            }
            else
            {
                // right rotation
                 if((child->left->priority < child->right->priority) && (child->priority > child->left->priority))
                {
                    TreapNode* temp = child->left;

                    parent->left = temp;

                    child->left = temp->right;

                    temp->right = child;
                   
                    return updateNonRootNode(head,parent->left, child);
                }
                else
                {
                    // left rotation
                    if((child->left->priority > child->right->priority) && (child->priority > child->right->priority))
                    {
                        TreapNode* temp = child->right;

                        parent->left = temp;

                        child->right = temp->left;

                        temp->left = child;
                        
                       return  updateNonRootNode(head,parent->left, child);
                    }
                    else
                    {
                        return head;
                    }
                    
                }
            }  
        }
        else
        {
            // when left child is present and right rotation.
            if((child->left && !child->right) && (child->priority > child->left->priority))
            {
                TreapNode* temp = child->left;

                parent->left = temp;

                child->left = temp->right;

                temp->right = child;
               
                return updateNonRootNode(head,parent->left, child);
            }
            else
            {
                // when right child is present and left rotation.
                if((!child->left && child->right)&& (child->priority > child->right->priority))
                {
                   // cout<<"Control is here "<<endl;
                    TreapNode* temp = child->right;

                    parent->left = temp;

                    child->right = temp->left;

                    temp->left = child;

                   return  updateNonRootNode(head,parent->left, child);
                }
                else
                {
                    
                    return head ;
                }
                
            }
            
        }
        
    }
    else
    {
        // child is right to the parent.
        if(parent->right == child )
        {
            if(child->left && child->right)
            {
                if((child->left->priority == child->right->priority) && (child->priority > child->left->priority))
                {   
                    TreapNode* temp = child->right;

                    parent->right = temp;

                    child->right = temp->right;

                    temp->left = child;
                    
                    return updateNonRootNode(head,parent->right, child);
                }
                else
                {
                    // right rotation
                    if((child->left->priority < child->right->priority) && (child->priority > child->left-> priority))
                    {
                        TreapNode* temp = child->left;

                        parent->right = temp;

                        child->left = temp->right;

                        temp->right = child;
                        
                        return updateNonRootNode(head,parent->right, child);
                    }
                    else
                    {
                        // left roatation
                        if((child->right->priority < child->left->priority) && (child->priority > child->right-> priority))
                        {
                            TreapNode* temp = child->right;

                            parent->right = temp;

                            child->right = temp->left;

                            temp->left = child;
                            
                            return  updateNonRootNode(head,parent->right, child);
                        }
                        else
                            return head;
                    }
                }
            }
            else
            {
                //when left child is present and right rotation
                if((child->left && !child->right) && (child->priority > child->left-> priority))
                {
                    TreapNode* temp = child->left;

                    parent->right = temp;

                    child->left = temp->right;

                    temp->right = child;
                    
                   return  updateNonRootNode(head,parent->right, child);
                }
                else
                {
                    // when right child is present and left rotation.
                    if((!child->left && child->right) && (child-> priority > child->right-> priority))
                    {
                        TreapNode* temp = child->right;

                        parent->right = temp;

                        child->right = temp->left;

                        temp->left = child;
                        
                        return updateNonRootNode(head,parent->right, child);
                    }
                    else
                    {
                        return head;
                    }
                    
                }
                
            }
            
        }
    }
}

TreapNode* updateRootNode(TreapNode* head, TreapNode* child)
{
    // root node has 2 children

    TreapNode* root = head;

    if(child->left && child->right)
    {
        // Both child are present.
        if((child->left->priority == child->right->priority) && (child->left-> priority < child->priority))
        {
            TreapNode* childRight = child->right;
            TreapNode* childRightLeft = child->right->left;

            childRight->left = child;
            child->right = childRightLeft;
            head = childRight;
            
            return updateNonRootNode(head,childRight, child);
        }
        else
        {
            if((child->left->priority < child->right->priority) && (child->priority > child->left->priority))
            {
                // when left child node has less priority
                TreapNode* childLeft = child->left;
                TreapNode* childLeftRight = child->left->right;

                childLeft->right = child;
                child->left = childLeftRight;
                head = childLeft;
                return updateNonRootNode(head,childLeft, child);
            }
            else
            {
                // when right child node has less priority
                if((child->left->priority > child->right->priority) && (child->priority > child->right->priority))
                { 
                     TreapNode* childRight = child->right;
                    TreapNode* childRightleft = child->right->left;

                     childRight->left = child;
                     child->right = childRightleft;
                     head = childRight;
                      return updateNonRootNode(head,childRight, child);
                }
                else
                {
                    return head;
                }
                
            }
            
        }
    }
    else
    {
        // when root->right does not exist 
        if((child->left && !child->right) && (child->priority > child->left->priority))
        {
            TreapNode* childLeft = child->left;
            TreapNode* childLeftRight = child->left->right;

            childLeft->right = child;
            child->left = childLeftRight;
            head = childLeft;
            return updateNonRootNode(head,childLeft, child);
        
        }
        else
        {
            //when root->left does not exist
            if((!child->left && child->right) && (child->priority > child->right->priority))
            {
               // cout<<"no left child "<<endl;
                TreapNode* childRight = child->right;
                TreapNode* childRightleft = child->right->left;

                childRight->left = child;
                child->right = childRightleft;
                head = childRight;
                 return updateNonRootNode(head,childRight, child);
                
            }
            else
            {
                return head;
            }
            
        }
        
    }
    
}
void  TreapNode :: updateNode(TreapNode* &head, int source, int destination)
{
    TreapNode* root = head;
    // we need to find that particular node first, then
    // we will update node.
   
    TreapNode* parent = nullptr;
    TreapNode* child = nullptr;

    pair<TreapNode*, TreapNode*> sourceAddress = searchNode(head, source, parent, child);
  

    if(sourceAddress.first->key != sourceAddress.second->key)
    {
        // incresing priority source node.
        sourceAddress.second->priority ++;

        sourceAddress.second->vec.push_back(destination);
       // cout<<"Pushing = "<< destination <<endl;

        head = updateNonRootNode(head,sourceAddress.first, sourceAddress.second);
        //return head;
    }
    else
    {
        // It does not have parent node, it means node to be updated is Root node.
        // increasing priority of source node.
        sourceAddress.second->priority ++;

        sourceAddress.second->vec.push_back(destination);
      
        head = updateRootNode(sourceAddress.second, sourceAddress.second);
        //return head;
    }
    
    
    // finidng parent node and destination node in the tree
     parent = nullptr;
     child = nullptr;

    pair<TreapNode*, TreapNode*> destinationAddress = searchNode(head, destination, parent, child);

    if(destinationAddress.first->key != destinationAddress.second->key)
    {

        // incresing the priority of destination node
        destinationAddress.second->priority ++;

        // inserting source node into destination node.
        destinationAddress.second->vec.push_back(source);

        head = updateNonRootNode(head,destinationAddress.first, destinationAddress.second);
        //return head;
    }
    else
    {
        // incresing the priority of destination node.
        destinationAddress.second->priority ++;

        // inserting source node into destination node.
        destinationAddress.second->vec.push_back(source);

        head = updateRootNode(destinationAddress.second, destinationAddress.second);
        //return head;
    }

}
#endif 