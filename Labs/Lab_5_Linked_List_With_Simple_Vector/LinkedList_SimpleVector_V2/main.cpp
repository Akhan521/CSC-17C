/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Created: October 5, 2022, 1:10 PM
 * Purpose: Creating some initial functions.
 */

//System Libraries.
#include <iostream>  //I/O Library.
#include <cstdlib>   //NULL Pointer.
using namespace std;

//User Libraries.
struct Link{
    int data;   //Some data.
    Link *next; //Next link.
};

//Global/Universal Constants -- No Global Variables.
//Science, Math, Conversions, Higher Dimensioned constants only.

//Function Prototypes.
Link *fillLst(int);    //To create and fill a list.
void prntLst(Link *);  //To print our linked list.
void dstryLst(Link *); //To destroy our linked list.

//Execution Begins Here:
int main(int argc, char** argv) {    
    //Creating and filling our list.
    Link *front=fillLst(5);
    
    //Printing the list.
    prntLst(front);
    
    //Deleting the list.
    dstryLst(front);
    
    //Exit stage right.
    return 0;
}

Link *fillLst(int n){
    //We begin by creating the front of our list.
    Link *front=new Link;
    //We set its data.
    front->data=1;
    //We have it point to NULL.
    front->next=NULL;
    //If n>1, then we create our additional links and join them.
    Link *temp=front; //To point to the current node we're on.
    for(int i=2;i<=n;i++){
        //We create a new link.
        Link *nxtLink=new Link;
        //We set its data.
        nxtLink->data=i;
        //We have our current node point to the new link.
        temp->next=nxtLink;
        //We update our temp to hold the new link as our current node.
        temp=nxtLink;
    }
    //We set the last node to point to NULL.
    temp->next=NULL;
    //We return the front of the list.
    return front;
}

void prntLst(Link *node){
    //As long as we have a valid node...
    while(node!=NULL){
        //We output its data.
        cout<<node->data<<endl;
        //We advance out pointer.
        node=node->next;
    }
}

void dstryLst(Link *front){
    //As long as we have a node to delete...
    while(front!=NULL){
        //We store the current node that needs to be deleted.
        Link *temp=front;
        //We advance to the next node/link.
        front=front->next;
        //We delete the stored node.
        delete temp;
    }
}