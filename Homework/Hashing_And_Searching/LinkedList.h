/* 
 * File:    LinkedList.h
 * Author:  Aamir Khan
 * Created: November 10, 2022, 11:35 AM
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
        LinkedList();         //Our constructor.
        ~LinkedList();        //Our destructor.
        void prntLst();       //To print our linked list.
        void dstryLst();      //To destroy our linked list.
        Link *create(T);      //Create a link with data.
        void push_back(T);    //Push a link to the end.
        bool isEmpty();       //To see if our list is empty.
        bool find(T);         //To see if a value is in our list.
};

template <class T>
LinkedList<T>::LinkedList(){
    front=NULL;
}

template <class T>
LinkedList<T>::~LinkedList(){
    dstryLst();
}

template <class T>
void LinkedList<T>::prntLst(){
    //cout<<"Printing list..."<<endl;
    Link *temp=front;
    //As long as we have a valid node...
    while(temp!=NULL){
        //We output its data.
        cout<<temp->data<<" ";
        //We advance out pointer.
        temp=temp->next;
    }
    cout<<endl;
}

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

template <class T>
void LinkedList<T>::push_back(T data){
    //Creating our new node/link.
    Link *node=create(data);
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

template <class T>
bool LinkedList<T>::isEmpty(){
    //If we have no front, our list is empty.
    if(front==NULL) return true;
    //Otherwise, it's not empty.
    return false;
}

template <class T>
bool LinkedList<T>::find(T item){
    //We go the front of our list.
    Link *temp=front;
    //We iterate through our list.
    while(temp!=NULL){
        //If we've found the item in our list, we return true.
        if(temp->data==item) return true;
        //Advance our pointer.
        temp=temp->next;
    }
    //Not found.
    return false;
}

#endif /* LINKEDLIST_H */

