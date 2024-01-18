#pragma once
#include <iostream>
using namespace std;

class treeNode
{
    public:
        int id;
        string bookName;
        string floor;
        string shelf;

        treeNode* left = NULL;
        treeNode* right = NULL;
};

class Tree
{
    public:
    treeNode* root = NULL;
    treeNode* ploc = NULL;
    treeNode* loc = NULL;

        bool isEmpty(){
            return (root == NULL);
        }
        
        void insertIntoTree(treeNode* newnode)
        {
            if(isEmpty())
            {
                root = newnode;
            }else
            {
                search(newnode->id);
                if (loc == NULL)
                {
                    if(ploc->id< newnode->id)
                    {
                        ploc->right = newnode;
                    }else
                    {
                        ploc->left = newnode;
                    }
                }
            }
        }

        treeNode* getFromTree(int id)
        {
            search(id);
            return loc;
        }

        void search(int id)
        {
            ploc = NULL;
            loc = root;
            while(loc != NULL && loc->id != id)
            {
                if(loc->id< id)
                {
                    ploc = loc;
                    loc = loc->right;
                }
                else
                {
                    ploc = loc;
                    loc= loc->left;
                }
            }
        }

        void editNode(int id,string newfloor, string newshelf)
        {
            search(id);
            if(loc != NULL)
            {
                loc->floor = newfloor;
                loc->shelf = newshelf;
            }
        }
        

};

// Global Tree Object
Tree bookTree;
