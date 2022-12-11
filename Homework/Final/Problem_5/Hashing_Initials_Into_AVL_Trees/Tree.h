/* 
 * File:    Tree.h
 * Author:  Aamir Khan
 * Created: Dec. 10, 2022, 3:15 PM
 */

#ifndef TREE_H
#define TREE_H

//Our System + User Libraries:
#include <iostream>  //I/O Library.
#include <ctime>     //Rand() + Srand().
#include <queue>     //Queues - Level-Order Traversal.
#include <cstdlib>   //CSTD Library.
#include "Node.h"    //Our Node struct.

class Tree{
    private:
        //Our root node.
        Node *root;
        //Utility functions:
        Node *newNode(string);        //Creates a new node.
        void prntPre(Node *);         //Pre-Order traversal.
        void prntIn(Node *);          //In-Order traversal.
        void prntPost(Node *);        //Post-Order traversal.
        void insert(Node *&,string);  //Inserts a node into our tree.
        void destroy(Node *&);        //Destroys our tree.
        int height(Node *);           //Determines the height of our tree.
        void delNode(Node *&,string); //Deletes a node from our tree.
        bool search(Node *,string);   //Searches our tree for a value.
        int size(Node *);             //Returns the size of a tree.
        Node *findMin(Node *);        //Finds the node w/ the smallest value.
        void lftRot(Node *&);         //Performs a left rotation about a root node.
        void rghtRot(Node *&);        //Performs a right rotation about a root node.
        void lftRghtRot(Node *&);     //Performs a left-right rotation about a root node.
        void rghtLftRot(Node *&);     //Performs a right-left rotation about a root node.
        void balance(Node *&);        //Balances our tree using tree rotations.
    public:
        //Our constructor.
        Tree(){root=NULL;}
        //Our destructor.
        ~Tree(){destroy(root);}
        //Pre-Order traversal.
        void prntPre(){prntPre(root); cout<<endl;}      
        //In-Order traversal.
        void prntIn(){prntIn(root); cout<<endl;} 
        //Post-Order traversal.
        void prntPost(){prntPost(root); cout<<endl;}
        //Level-Order traversal.
        void prntLvl(); 
        //Inserts a node into our tree.
        void insert(string value){insert(root,value);}   
        //Determines the height of our tree.
        int height(){return height(root);}
        //Deletes a node from our tree.
        void delNode(string value){delNode(root,value);}
        //Finds the node w/ the smallest value.
        Node *findMin(){return findMin(root);}
        //Searches our tree for a value.
        bool search(string target){return search(root,target);}
        //Returns the size of our tree. (# of nodes in our tree.)
        int size(){return size(root);}
};

#endif /* TREE_H */

