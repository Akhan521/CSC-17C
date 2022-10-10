/* 
 * File:    LinkedList.cpp
 * Author:  Aamir Khan
 * Created: October 9, 2022, 4:10 PM
 */

#include "LinkedList.h"

LinkedList::LinkedList(int n){
    front=NULL;
    end=NULL;
    fillLst(n);
}

LinkedList::~LinkedList(){
    dstryLst();
}

LinkedList::Link *LinkedList::fillLst(int n){
    cout<<"Creating our list..."<<endl;
    //We begin by creating the front of our list.
    front=new Link;
    //We set its data.
    front->data=1;
    //We have it point to NULL.
    front->prev=NULL;
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
        //We have our new link's prev point to the current node.
        nxtLink->prev=temp;
        //We update our temp to hold the new link as our current node.
        temp=nxtLink;
    }
    //We set the last node as our list's end.
    end=temp;
    //We set the last node to point to NULL.
    temp->next=NULL;
    //We return the front of the list.
    return front;
}

void LinkedList::prntLst(){
    cout<<"Printing list..."<<endl;
    Link *temp=front;
    //As long as we have a valid node...
    while(temp!=NULL){
        //We output its data.
        cout<<temp->data<<" ";
        //We advance out pointer.
        temp=temp->next;
    }
    cout<<endl<<endl;
}

void LinkedList::prntRev(){
    cout<<"Printing in reverse..."<<endl;
    Link *temp=end;
    //As long as we have a valid node...
    while(temp){
        //We output its data.
        cout<<temp->data<<" ";
        //We go to the previous node.
        temp=temp->prev;
    }
    cout<<endl<<endl;
}

void LinkedList::dstryLst(){
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

LinkedList::Link *LinkedList::create(int n){
    //We create our new link.
    Link *link=new Link;
    //We set its data and pointers.
    link->data=n;
    link->prev=NULL;
    link->next=NULL;
    //We return the new link;
    return link;
}

void LinkedList::push_front(int n){
    //Creating our node.
    Link *node=create(n);
    //If we have no front...
    if(front==NULL){
        front=node; //This is our first node.
    }
    else{
        //We have our current front's prev point to the new node.
        front->prev=node;
        //We have our node point to the current front of our list.
        node->next=front;
        //We then set our node to be the new front.
        front=node;
    }
}

void LinkedList::push_back(int n){
    //Creating our node.
    Link *node=create(n);
    //If we have no front...
    if(front==NULL){
        front=node; //This is our first node.
    }
    else{
        //We have to go to the last node:
        Link *temp=end;
        //We then insert our new node at the end.
        temp->next=node;
        //We set our new node's prev as our former end.
        node->prev=temp;
        //Mark our new node as our new end.
        end=node;
    }
}

int LinkedList::pop_front(){
    //To hold the popped data.
    int popped=-1;
    //If the list is already empty...
    if(front==NULL){
        cout<<"The list is already empty..."<<endl;
    }
    //If we only have 1 node to delete...
    else if(front!=NULL&&front->next==NULL){
        //We store the data to be popped.
        popped=front->data;
        //We delete the front/last node.
        delete front;
        //We have our list point to NULL.
        front=NULL;
    }
    //If we have more than 1 node in our list...
    else{
        Link *temp=front;
        //We store the data that will be popped.
        popped=front->data;
        //We set our 2nd node as our new front.
        front=front->next;
        //We need to set the new front's prev to NULL.
        front->prev=NULL;
        //We delete the former front.
        delete temp;
    }
    //We return the popped data.
    return popped;
}

int LinkedList::pop_back(){
    //To hold the popped data.
    int popped=-1;
    //If the list is already empty...
    if(front==NULL){
        cout<<"The list is already empty..."<<endl;
    }
    //If we only have 1 node to delete...
    else if(front!=NULL&&front->next==NULL){
        //We store the data to be popped.
        popped=front->data;
        //We delete the front/last node.
        delete front;
        //We have our list point to NULL.
        front=NULL;
    }
    //If we have more than 1 node in our list...
    else{
        //We have to find the last node and the one before it:
        Link *last=end;           //The last node.
        Link *scndLast=end->prev; //The 2nd to last node.
        //We store the data that will be popped.
        popped=last->data; 
        //We delete the last node.
        delete last;
        //We have our 2nd to last node point to NULL.
        scndLast->next=NULL;
        //We update our new end.
        end=scndLast;
    }
    //Returning our popped data;
    return popped;
}