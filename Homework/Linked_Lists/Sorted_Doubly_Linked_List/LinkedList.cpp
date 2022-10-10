/* 
 * File:    LinkedList.cpp
 * Author:  Aamir Khan
 * Created: October 9, 2022, 6:10 PM
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
    //We set the end's prev to the 2nd to last node.
    end->prev=temp->prev;
    //We set the last node to point to NULL.
    end->next=NULL;
    //We sort our list.
    sort();
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
    //We set our end to NULL.
    end=NULL;
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

void LinkedList::push(int n){
    cout<<"Inserting: "<<n<<endl;
    //Creating our node.
    Link *node=create(n);
    //If we have no front...
    if(front==NULL){
        front=node; //This is our first node.
        end=node;   //This is also our last node.
    }
    //If we have to place our node at the front...
    else if(node->data<front->data){
        //We set the front's prev to the new node.
        front->prev=node;
        //We set the new node's next to front.
        node->next=front;
        //Our new node becomes our new front.
        front=node;
    }
    //If we need to insert the node elsewhere...
    else{
        //We need to find the correct insert position for our node.
        Link *temp=front;
        //While the next node is valid and its data is 
        //less than our new node's data, we advance our pointer.
        while(temp->next&&temp->next->data<node->data){
            //Moving to the next node.
            temp=temp->next;
        }
        //We can now insert our new node into our list.
        //temp holds the node that will come before our new node.
        //temp->next holds the node that will come after our new node.
        //We set the new node's next to the node that will come after.
        node->next=temp->next;
        //We set the next node's prev to our new node.
        temp->next->prev=node;
        //We set the current node's next to our new node.
        temp->next=node;
        //We set our new node's prev to the current node.
        node->prev=temp;
        //If we inserted the node at the end...
        if(node->data>end->data){
            //We update our end.
            end=node;
        }
        //NOTE: If we had inserted our node at the front or in between, the end
        //wouldn't need to be updated. We only have to update our end if we are
        //inserting our node at the end of our list. In this case, our new node
        //will become our last node. (This is when its data is larger than the
        //last node's data).
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

int LinkedList::size(){
    //To hold our size.
    int count=0;
    //We loop through our list.
    Link *temp=front;
    while(temp){
        //We increment our count.
        count++;
        //We advance our pointer.
        temp=temp->next;
    }
    //We return our size.
    return count;
}

void LinkedList::sort(){
    //To use in our outer loop.
    Link *tmp1=front;
    //We sort using a nested for loop.
    for(int i=0;i<size()-1;i++){
        //To use in our inner loop.
        Link *tmp2=tmp1->next;
        //We start from the next node and go through our list.
        for(int j=i+1;j<size();j++){
            //If we need to swap our data...
            if(tmp1->data>tmp2->data){
                //We swap our data.
                int temp=tmp1->data;
                tmp1->data=tmp2->data;
                tmp2->data=temp;
            }
            //We advance our pointer.
            tmp2=tmp2->next;
        }
        //We advance our pointer.
        tmp1=tmp1->next;
    }
}