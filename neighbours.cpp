
#ifndef NEI
#define NEI

#include<bits/stdc++.h>
#include "addition.cpp"

TreapNode* searchNode(TreapNode* head, int i)
{
    if(head->key == i)
        return head;
    
    if(head->key > i)
        searchNode(head->left,  i);
    else
        searchNode(head->right, i);   
}

void TreapNode:: findNeighbour(TreapNode* head)
{
    set<int> mySet;
    
    for( int i = 1; i <= 26; i++)
    {
        TreapNode* nodeAddress = searchNode(head, i);
        vector<int> myVec;

        set<int>noElement;
        
        noElement.insert(i);

        // copying all the neighbouring node into set
         for( int j = 0 ; j < nodeAddress->vec.size(); j++)
        {
            mySet.insert(nodeAddress->vec[j]);
            myVec.push_back(nodeAddress->vec[j]);
            noElement.insert(nodeAddress->vec[j]);
        }

        auto itr = mySet.begin();
        for(; itr != mySet.end(); itr++)
        {
            nodeAddress = searchNode(head,*itr);
            int no = *itr;
            for(int j = 0 ; j < nodeAddress->vec.size(); j++)
            {
                 auto pos = noElement.find(nodeAddress->vec[j]);
                 if(pos == noElement.end())
                {   
                    auto s = mySet.find(nodeAddress->vec[j]);
                    if(s == mySet.end())
                    {
                        myVec.push_back(nodeAddress->vec[j]);
                        noElement.insert(nodeAddress->vec[j]);
                    }     
                }
            }
            mySet.erase(itr);
        }
        neighborNode.push_back(myVec);
        myVec.clear();
        noElement.clear();
    }

   // cout<<" Calculating NBF "<<endl;

    // creating NBF
    vector<int> NBF(26, 1);

    for( int i = 1; i < 26; i++)
    {
        for( int j = i+1; j < 27; j++)
        {
            vector<int> v;
            int iSize = neighborNode[i].size();
            int jSize = neighborNode[j].size();

            vector<int> vI;
            vector<int> vJ;

            for( int k = 0; k < iSize; k++)
            {
                vI.push_back(neighborNode[i][k]);
            }
            for(int k = 0 ; k < jSize; k++)
            {
                vJ.push_back(neighborNode[j][k]);
            }
            //cout<<"elements copied "<<endl;

            sort(vI.begin(), vI.begin() + iSize);
            sort(vJ.begin(), vJ.begin() + jSize);

           
            set_intersection(vI.begin(), vI.begin()+ iSize, vJ.begin(), vJ.begin()+ jSize, back_inserter(v));


            if((NBF[i] == NBF[j]) && (v.size() == 0))
            {
               // cout<<"NBF"<<endl;
                NBF[j] = NBF[j] + 1;
            }

            vI.clear();
            vJ.clear();
            v.clear();
        }
    }

    //cout<< "Creating MF vector "<<endl;
    //vector<int> MF;
    int j = 1;
    MF.push_back(0);
    for(int i = 1; i <= 26; i++)
    {
        if(i >= 1 && i <= 7)
        {
            j = 1;
            MF.push_back(j);
        }
        else
        {
            if(i >= 8 && i <= 10)
            {
                j = 2;
                MF.push_back(j);
            }
            else
            {
                if(i >= 11 && i <= 18)
                {
                    j = 3;
                    MF.push_back(j);
                }
                else
                {
                    if(i >= 19 && i <= 22)
                    {
                        j = 4;
                        MF.push_back(j);
                    }
                    else
                    {
                        if(i >= 23 && i <= 24)
                        {
                            j = 5;
                            MF.push_back(j);
                        }
                        else
                        {
                            j = 6;
                            MF.push_back(j);
                        }
                        
                    }   
                }   
            }       
        }     
    }
/*
    for(auto i : MF)
        cout << i <<" ";
        cout<<endl;
        */
}
#endif