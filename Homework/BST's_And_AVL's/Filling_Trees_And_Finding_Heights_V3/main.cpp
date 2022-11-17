/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Created: November 16, 2022, 1:15 PM
 * Purpose: Filling a tree and finding its height.
 */

//System Libraries:
#include <iostream>  //I/O Library.
#include <ctime>     //Rand() + Srand().
#include <queue>     //Queues - Level-Order Traversal.
using namespace std;

//User Libraries:
#include "Node.h"

//Global Constants.
//Math, Science, Universal, Conversions, High Dimensioned Arrays.

//Function Prototypes:
Node *newNode(int);       //Creates a new node.
void prntPre(Node *);     //Pre-Order traversal.
void prntIn(Node *);      //In-Order traversal.
void prntPost(Node *);    //Post-Order traversal.
void prntLvl(Node *);     //Level-Order traversal.
void insert(Node *&,int); //Inserts a node into our tree.
void destroy(Node *&);    //Destroys our tree.
Node *fill(int);          //Fills a tree with randomly-filled nodes.
int height(Node *);       //Determines the height of our tree.

//Execution Begins Here:
int main(int argc, char** argv) {
    //Initialize the Random Number Seed.
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables.
    Node *root=NULL; //Our root node.
    int nNodes=10;   //The # of nodes that will be in our tree.
    
    //Filling our tree w/ random data:
    root=fill(nNodes);
    
    //Display Inputs/Outputs.
    cout<<"\nIn-Order Traversal:\n";
    prntIn(root);
    cout<<endl;
    cout<<"\nLevel-Order Traversal:\n";
    prntLvl(root);
    cout<<endl;
    cout<<"\nHeight = "<<height(root);
    cout<<endl;
    
    //Exit the Program - Cleanup.
    destroy(root); //Destroying our tree.
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
//Inserts a node recursively.
void insert(Node *&root,int value){
    //Base case: If we have an invalid node, we
    //create a new node and assign it to root.
    //(This is the insertion taking place.)
    if(root==NULL) root=newNode(value);
    //Otherwise, if we have a valid node...
    else{
        //If the value we're trying to insert is less than the 
        //current node's data, we'll be inserting into the left subtree.
        if(value<root->data){
            insert(root->left,value);
        }
        //Otherwise, we'll be inserting into the right subtree.
        else insert(root->right,value);
    }
}
//Destroys our tree using post-order traversal.
void destroy(Node *&root){
    //Base case:
    if(root==NULL) return;
    //Left->Right->Root;
    destroy(root->left);
    destroy(root->right);
    //cout<<"Deleting: "<<root->data<<endl;
    delete root; //Deallocating the node's memory.
    root=NULL;   //Setting it to NULL.
}
//Fills a tree w/ random data and a specified number of nodes.
Node *fill(int n){
    //Declaring our root node.
    Node *root=NULL;
    //Inserting N nodes:
    for(int i=1;i<=n;i++){
        //Inserting a node w/ a random value between 10-99.
        insert(root,rand()%90+10);
    }
    //Returning our root node.
    return root;
}
//Determines the height of our tree recursively.
int height(Node *root){
    //Base case:
    if(root==NULL) return 0;
    //Recursively finding the heights of the subtrees.
    int lHeight=height(root->left);  //Height of the left subtree.
    int rHeight=height(root->right); //Height of the right subtree.
    //Returning the correct height.
    //(We add 1 to account for the root node.)
    if(lHeight>rHeight) return lHeight+1;
    else return rHeight+1;
}