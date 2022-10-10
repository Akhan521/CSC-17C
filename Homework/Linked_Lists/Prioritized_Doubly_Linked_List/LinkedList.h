/* 
 * File:    LinkedList.h
 * Author:  Aamir Khan
 * Created: October 9, 2022, 6:10 PM
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
        Link *prev; //Previous link.
        };
        //The front of our list.
        Link *front=NULL;
        //The end of our list.
        Link *end=NULL;
    public:
        LinkedList(int);         //Our constructor.
        ~LinkedList();           //Our destructor.
        Link *fillLst(int);      //To create and fill a list.
        void prntLst();          //To print our linked list.
        void prntRev();          //To print our list in reverse.
        void dstryLst();         //To destroy our linked list.
        Link *create(T);         //Create a link with data.
        void push_front(T);      //Push a link to the front.
        void push_back(T);       //Push a link to the end.
        T pop_front();           //Pop a link from the front.
        T pop_back();            //Pop a link from the end.
        void find(T);            //Search our list for the 1st 
                                 //occurrence of a value.
};

template <class T>
LinkedList<T>::LinkedList(int n){
    front=NULL;
    end=NULL;
    fillLst(n);
}

template <class T>
LinkedList<T>::~LinkedList(){
    dstryLst();
}

template <class T>
typename LinkedList<T>::Link *LinkedList<T>::fillLst(int n){
    cout<<"Creating our list..."<<endl;
    //We begin by creating the front of our list.
    front=new Link;
    //We set its data.
    front->data=rand()%90+10; //10-99.
    //We have it point to NULL.
    front->prev=NULL;
    front->next=NULL;
    //If n>1, then we create our additional links and join them.
    Link *temp=front; //To point to the current node we're on.
    for(int i=2;i<=n;i++){
        //We create a new link.
        Link *nxtLink=new Link;
        //We set its data.
        nxtLink->data=rand()%90+10; //10-99.
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
    end->next=NULL;
    //We return the front of the list.
    return front;
}

template <class T>
void LinkedList<T>::prntLst(){
    cout<<endl;
    int perLine=20; //How many elements to display per line.
    int count=0;    //To keep count of how many elements we've displayed.
    cout<<"Printing list..."<<endl;
    Link *temp=front;
    //As long as we have a valid node...
    while(temp!=NULL){
        //We output its data.
        cout<<temp->data<<" ";
        //We advance out pointer.
        temp=temp->next;
        //If we have 15 elements on a line, we go to the next line.
        if(count++%perLine==perLine-1)
            cout<<endl;
    }
    cout<<endl;
}

template <class T>
void LinkedList<T>::prntRev(){
    cout<<endl;
    int perLine=20; //How many elements to display per line.
    int count=0;    //To keep count of how many elements we've displayed.
    cout<<"Printing in reverse..."<<endl;
    Link *temp=end;
    //As long as we have a valid node...
    while(temp){
        //We output its data.
        cout<<temp->data<<" ";
        //We go to the previous node.
        temp=temp->prev;
        //If we have 15 elements on a line, we go to the next line.
        if(count++%perLine==perLine-1)
            cout<<endl;
    }
    cout<<endl;
}

template <class T>
void LinkedList<T>::dstryLst(){
    //As long as we have a node to delete...
    while(front!=NULL){
        //We store the current node that needs to be deleted.
        Link *temp=front;
        //We advance to the next node/link.
        front=front->next;
        //We delete the stored node.
        delete temp;
    }
    //We set our end to NULL.
    end=NULL;
}

template <class T>
typename LinkedList<T>::Link *LinkedList<T>::create(T data){
    //We create our new link.
    Link *link=new Link;
    //We set its data and pointers.
    link->data=data;
    link->prev=NULL;
    link->next=NULL;
    //We return the new link;
    return link;
}

template <class T>
void LinkedList<T>::push_front(T data){
    //Creating our node.
    Link *node=create(data);
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

template <class T>
void LinkedList<T>::push_back(T data){
    //Creating our node.
    Link *node=create(data);
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
        end=NULL;
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
        end=NULL;
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

template <class T>
void LinkedList<T>::find(T val){
    Link *temp=front;
    //As long as we have a valid node and we haven't found our data...
    while(temp&&temp->data!=val){
        //We advance our pointer.
        temp=temp->next;
    }
    //If we have a valid node and we've found our data...
    if(temp&&temp->data==val){
        //We output that the data was found.
        cout<<val<<" was found!"<<endl;
        //temp holds the node with the data we've found.
        //Note: if the link is already at the front, we do nothing.
        //If the link is in between our list...
        if(temp!=front&&temp!=end){
            //We set the previous node's next to the next node.
            temp->prev->next=temp->next;
            //We set the next node's prev to the previous node.
            temp->next->prev=temp->prev;
            //We want to bring the current node to the front:
            temp->next=front; //We set the current node's next to our front.
            front->prev=temp; //We set our front's prev to the current node.
            front=temp;       //We set the current node as our new front.
            front->prev=NULL; //We set its prev to NULL, since it is our front.
        }
        //If the node we've found is the end of our list...
        else if(temp==end){
            //We set the 2nd to last node as our new end.
            end=end->prev;
            //We have the last node point to NULL.
            end->next=NULL;
            //We want to bring the current node to the front:
            temp->next=front; //We set the current node's next to our front.
            front->prev=temp; //We set our front's prev to the current node.
            front=temp;       //We set the current node as our new front.
            front->prev=NULL; //We set its prev to NULL, since it is our front.
        }
    }
    //If we didn't find the data...
    else{
        //We output that the value wasn't found.
        cout<<val<<" was NOT found."<<endl;
    }
}

#endif /* LINKEDLIST_H */

