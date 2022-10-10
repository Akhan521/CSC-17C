/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Created: October 5, 2022, 1:30 PM
 * Purpose: Adding insertion and deletion to our list.
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
//The front of our list.
Link *front=NULL;

//Global/Universal Constants -- No Global Variables.
//Science, Math, Conversions, Higher Dimensioned constants only.

//Function Prototypes.
Link *fillLst(int);    //To create and fill a list.
void prntLst(Link *);  //To print our linked list.
void dstryLst(Link *); //To destroy our linked list.
//Newly Added Functions:
Link *create(int);       //Create a link with data.
void push_front(Link *); //Push a link to the front.
void push_back(Link *);  //Push a link to the end.
Link *pop_front();       //Pop a link from the front.
Link *pop_back();        //Pop a link from the end.

//Execution Begins Here:
int main(int argc, char** argv) {
    //Setting the random number seed.
    //srand(static_cast<unsigned int>(time(0)));
    
    //Creating and filling our list.
    front=fillLst(5);
    
    //Printing the list.
    prntLst(front);
    
    //Inserting 2 new links at the front.
    cout<<"Inserting 2 links at the front."<<endl;
    Link *lnk1=create(6);
    Link *lnk2=create(7);
    push_front(lnk1);
    push_front(lnk2);
    //Printing our modified list.
    prntLst(front);
    
    //Inserting 2 new links at the back.
    cout<<"Inserting 2 links at the back."<<endl;
    Link *lnk3=create(8);
    Link *lnk4=create(9);
    push_back(lnk3);
    push_back(lnk4);
    //Printing our modified list.
    prntLst(front);
    
    //Popping 2 elements from the front.
    cout<<"Popping 2 links at the front."<<endl;
    Link *popped1=pop_front();
    Link *popped2=pop_front();
    if(popped1!=NULL)
        cout<<"The 1st popped element is: "<<popped1->data<<endl;
    if(popped2!=NULL)
        cout<<"The 2nd popped element is: "<<popped2->data<<endl;
    //Printing our modified list.
    prntLst(front);
    
    //Popping 2 elements from the back.
    cout<<"Popping 2 links at the back."<<endl;
    Link *popped3=pop_back();
    Link *popped4=pop_back();
    if(popped3!=NULL)
        cout<<"The 1st popped element is: "<<popped3->data<<endl;
    if(popped4!=NULL)
        cout<<"The 2nd popped element is: "<<popped4->data<<endl;
    //Printing our modified list.
    prntLst(front);
    
    //Deleting the list.
    dstryLst(front);
    //Deleting the nodes we popped.
    delete popped1,popped2,
           popped3,popped4;
    
    //Exit stage right.
    return 0;
}

Link *fillLst(int n){
    cout<<"Creating our list..."<<endl;
    //We begin by creating the front of our list.
    front=new Link;
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
    cout<<"Printing list..."<<endl;
    //As long as we have a valid node...
    while(node!=NULL){
        //We output its data.
        cout<<node->data<<" ";
        //We advance out pointer.
        node=node->next;
    }
    cout<<endl<<endl;
}

void dstryLst(Link *front){
    //As long as we have a node to delete...
    while(front!=NULL){
        //We store the current node that needs to be deleted.
        Link *temp=front;
        //cout<<"Deleting: "<<temp->data<<endl;
        //We advance to the next node/link.
        front=front->next;
        //We delete the stored node.
        delete temp;
    }
}

Link *create(int n){
    //We create our new link.
    Link *link=new Link;
    //We set its data and pointer.
    link->data=n;
    link->next=NULL;
    //We return the new link;
    return link;
}

void push_front(Link *node){
    cout<<"Inserting: "<<node->data<<endl;
    //If we have no front...
    if(front==NULL){
        front=node; //This is our first node.
    }
    else{
        //We have our node point to the current front of our list.
        node->next=front;
        //We then set our node to be the new front.
        front=node;
    }
}

void push_back(Link *node){
    cout<<"Inserting: "<<node->data<<endl;
    //If we have no front...
    if(front==NULL){
        front=node; //This is our first node.
    }
    else{
        //We have to find the last node:
        Link *temp=front;
        //We want to stop at the very last node, so we keep
        //advancing as long as the next node is a valid node.
        while(temp->next!=NULL){
            temp=temp->next;
        }
        //We then insert our new node.
        temp->next=node;
    }
}

Link *pop_front(){
    //To hold the popped node.
    Link *popped;
    //If the list is already empty...
    if(front==NULL){
        cout<<"The list is already empty..."<<endl;
        popped=NULL;
    }
    //If we only have 1 node to delete...
    else if(front!=NULL&&front->next==NULL){
        //We store the node to be popped.
        popped=front;
        //We have our list point to NULL.
        front=NULL;
    }
    //If we have more than 1 node in our list...
    else{
        //We store the node that will be popped.
        popped=front;
        //We set our 2nd node as our new front.
        front=front->next;
    }
    //We return the popped node.
    return popped;
    //Note: we delete the popped links in main.
}

Link *pop_back(){
    //To hold the popped node.
    Link *popped;
    //If the list is already empty...
    if(front==NULL){
        cout<<"The list is already empty..."<<endl;
        popped=NULL;
    }
    //If we only have 1 node to delete...
    else if(front!=NULL&&front->next==NULL){
        //We store the node to be popped.
        popped=front;
        //We have our list point to NULL.
        front=NULL;
    }
    //If we have more than 1 node in our list...
    else{
        //We have to find the 2nd to last node:
        Link *temp=front;
        //We want to stop at the 2nd to last node, as this will become our 
        //last node. We keep advancing as long as the next 2 nodes are valid.
        //This will ensure that we stop at the 2nd to last node in our list.
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        //We store the node that will be popped.
        popped=temp->next; 
        //We set our 2nd to last node as our last.
        temp->next=NULL;
    }
    //Returning our popped node;
    return popped;
    //Note: we delete the popped links in main.
}