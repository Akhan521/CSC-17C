/* 
 * File:    LinkedList.h
 * Author:  Aamir Khan
 * Created: October 5, 2022, 9:45 PM
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream> //I/O Library.
#include <cstdlib>  //NULL Pointer.
using namespace std;

template <class T>
class LinkedList{
    private:
        //Our link structure.
        struct Link{
        T data;     //Some data.
        Link *next; //Next link.
        };
        //The front of our list.
        Link *front=NULL;
    public:
        LinkedList(int);          //Our constructor.
        ~LinkedList();            //Our destructor.
        Link *fillLst(int);       //To create and fill a list.
        void prntLst();           //To print our linked list.
        void dstryLst();          //To destroy our linked list.
        Link *create(T);          //Create a link with data.
        Link *operator[](const int); //Overloaded [] operator.
        void push_front(Link *);  //Push a link to the front.
        void push_back(Link *);   //Push a link to the end.
        T pop_front();            //Pop a link from the front.
        T pop_back();             //Pop a link from the end.
        int getSize();            //Return the size of the list.
};

//Our constructor.
template <class T>
LinkedList<T>::LinkedList(int n){
    //We set the front to NULL.
    front=NULL;
    //If we want to create nodes...
    if(n>0){
        //We fill our list.
        fillLst(n);
    }
}

//Destructor to destroy our linked list.
template <class T>
LinkedList<T>::~LinkedList(){
    dstryLst();
}

//Fill list function to create and fill a list.
template <class T>
typename LinkedList<T>::Link *LinkedList<T>::fillLst(int n){
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

//Print list function.
template <class T>
void LinkedList<T>::prntLst(){
    int perLine=10; //How many elements to display per line.
    int count=0;    //A count of our elements.
    cout<<"Printing list..."<<endl;
    Link *temp=front;
    //As long as we have a valid node...
    while(temp!=NULL){
        //We output its data.
        cout<<temp->data<<" ";
        //We advance out pointer.
        temp=temp->next;
        //We want 10 elements per line.
        if(count++%perLine==perLine-1)
            //If we have elements to place on the next line...
            if(getSize()>perLine)
                //Then, we output a new line.
                cout<<endl;
    }
    cout<<endl<<endl;
}

//Destroy list function.
template <class T>
void LinkedList<T>::dstryLst(){
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

//Create function to create a link with the given data.
template <class T>
typename LinkedList<T>::Link *LinkedList<T>::create(T data){
    //We create our new link.
    Link *link=new Link;
    //We set its data and pointer.
    link->data=data;
    link->next=NULL;
    //We return the new link;
    return link;
}

//Overloaded [] operator which returns the indexed node.
template <class T>
typename LinkedList<T>::Link *LinkedList<T>::operator[](const int sub){
    //If we have a valid index...
    if(sub>=0&&sub<getSize()){
        int count=0;
        Link *temp=front;
        //We find our node given our index.
        while(count++!=sub){
            //We advance our pointer.
            temp=temp->next;
        }
        //We return the indexed node.
        return temp;
    }
    return NULL;
}

//Push front function.
template <class T>
void LinkedList<T>::push_front(Link *node){
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

//Push back function.
template <class T>
void LinkedList<T>::push_back(Link *node){
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

//Pop front function.
template <class T>
T LinkedList<T>::pop_front(){
    //To hold the popped data.
    T popped=-1;
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
        //We delete the former front.
        delete temp;
    }
    //We return the popped data.
    return popped;
}

//Pop back function.
template <class T>
T LinkedList<T>::pop_back(){
    //To hold the popped data.
    T popped=-1;
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
        //We have to find the last node:
        Link *prev=NULL;  //To hold the previous node.
        Link *curr=front; //To hold the current node.
        //We traverse to the last node.
        while(curr->next!=NULL){
            prev=curr;
            curr=curr->next;
        }
        //We store the data that will be popped.
        popped=curr->data; 
        //We delete the last node.
        delete curr;
        //We have our 2nd to last node point to NULL.
        prev->next=NULL;
    }
    //Returning our popped data;
    return popped;
}

//Get size function to return our list's size.
template <class T>
int LinkedList<T>::getSize(){
    int count=0;
    if(front!=NULL){
        Link *temp=front;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
    }
    return count;
}

#endif /* LINKEDLIST_H */

