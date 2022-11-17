/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Created: November 16, 2022, 12:20 PM
 * Purpose: Tree Traversal Methods.
 */

//System Libraries:
#include <iostream>  //I/O Library.
#include <queue>     //Queues - Level-Order Traversal.
using namespace std;

//User Libraries:
#include "Node.h"

//Global Constants.
//Math, Science, Universal, Conversions, High Dimensioned Arrays.

//Function Prototypes:
Node *newNode(int);    //Creates a new node.
void prntPre(Node *);  //Pre-Order traversal.
void prntIn(Node *);   //In-Order traversal.
void prntPost(Node *); //Post-Order traversal.
void prntLvl(Node *);  //Level-Order traversal.

//Execution Begins Here:
int main(int argc, char** argv) {
    //Initialize the Random Number Seed.
    
    //Declare Variables.
    Node *root=newNode(2);  //Our root node.
    root->left=newNode(1);  //Left-child.
    root->right=newNode(3); //Right-child.
    
    //Initialize Variables.
    
    //Map Inputs to Outputs -> Process.
    
    //Display Inputs/Outputs.
    cout<<"\nPre-Order Traversal:\n";
    prntPre(root);
    cout<<"\nIn-Order Traversal:\n";
    prntIn(root);
    cout<<"\nPost-Order Traversal:\n";
    prntPost(root);
    cout<<"\nLevel-Order Traversal:\n";
    prntLvl(root);
    
    //Exit the Program - Cleanup.
    delete root->left;
    delete root->right;
    delete root;
    return 0;
}
//Creates a new node and initializes it.
Node *newNode(int value){
    //Allocating memory for our new node.
    Node *node=new Node;
    //Setting its data.
    node->data=value;
    //Setting its pointers.
    node->left=NULL;
    node->right=NULL;
    //Returning our new node.
    return node;
}
//Pre-Order traversal.
void prntPre(Node *root){
    //Base case:
    if(root==NULL) return;
    //Root->Left->Right:
    cout<<root->data<<" ";
    prntPre(root->left);
    prntPre(root->right);
}
//In-Order traversal.
void prntIn(Node *root){
    //Base case:
    if(root==NULL) return;
    //Left->Root->Right:
    prntIn(root->left);
    cout<<root->data<<" ";
    prntIn(root->right);
}
//Post-Order traversal.
void prntPost(Node *root){
    //Base case:
    if(root==NULL) return;
    //Left->Right->Root:
    prntPost(root->left);
    prntPost(root->right);
    cout<<root->data<<" ";
}
//Level-Order traversal.
void prntLvl(Node *root){
    //Creating an empty queue.
    queue<Node *> q;
    //Storing the root in a temp. variable.
    Node *temp=root;
    //Looping while we have a valid node:
    while(temp){
        //1. Outputting the current node's data.
        cout<<temp->data<<" ";
        //2. Enqueueing its children.
        if(temp->left)  q.push(temp->left);
        if(temp->right) q.push(temp->right);
        //3. Dequeueing a node and assigning it to temp.
        if(!q.empty()){
            //Assigning the node at the front to temp.
            temp=q.front();
            //Popping the assigned node off of our queue.
            q.pop();
        }
        //If the queue is empty, we have no nodes to display.
        else temp=NULL;
    }
}
