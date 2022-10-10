/* 
 * File:    LinkedList.h
 * Author:  Aamir Khan
 * Created: October 9, 2022, 4:10 PM
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream> //I/O Library.
#include <cstdlib>  //NULL Pointer.
using namespace std;

class LinkedList{
    private:
        //Our link structure.
        struct Link{
        int data;   //Some data.
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
        Link *create(int);       //Create a link with data.
        void push_front(int);    //Push a link to the front.
        void push_back(int);     //Push a link to the end.
        int pop_front();         //Pop a link from the front.
        int pop_back();          //Pop a link from the end.
    
};

#endif /* LINKEDLIST_H */

