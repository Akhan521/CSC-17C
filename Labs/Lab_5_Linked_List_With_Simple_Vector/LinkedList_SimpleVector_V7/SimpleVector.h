/*
 * Modified Simple Vector class definition.
 * This class is implemented using a linked list.
 * Author of Linked List: Aamir Khan
 */

#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include "LinkedList.h"

template <class T>
class SimpleVector{
//Private members:
private:
   LinkedList<T> *list; // Our linked list.
   int arraySize;       // Number of elements.
   void subError();     // Handles out of range subscripts.
//Public members:
public:
   //Default constructor.
   SimpleVector(){
       //Setting the size to 0.
       arraySize=0;
       //Creating an empty list.
       list=new LinkedList<T>(arraySize);
   }
   // Constructor declaration.
   SimpleVector(int n){
       //Setting our size;
       arraySize=n;
       //Creating our list with data from 1 to n.
       list=new LinkedList<T>(arraySize);
   }
   // Copy constructor declaration.
   SimpleVector(SimpleVector &);
   // Destructor declaration.
   ~SimpleVector();
   // Print function.
   void print(){
       list->prntLst();
   }
   // Accessor to return the array size.
   int size() const{
       return arraySize;
   }
   // Overloaded [] operator declaration.
   T &operator[](const int &);
   //Insert functions:
   void push_front(T);
   void push_back(T);
   //Delete functions:
   T pop_front();
   T pop_back();
};

//Push front function to insert an element at the front.
template <class T>
void SimpleVector<T>::push_front(T data){
    //Setting our new size.
    arraySize++;
    //Pushing our node to the front of the linked list.
    list->push_front(list->create(data));
}

//Push back function to insert an element at the back.
template <class T>
void SimpleVector<T>::push_back(T data){
   //Setting our new size.
    arraySize++;
    //Pushing our node to the back of the linked list.
    list->push_back(list->create(data));
}

//Pop front function to remove an element from the front.
template <class T>
T SimpleVector<T>::pop_front(){
    //Setting our new size.
    arraySize--;
    //Popping a node from the front of the linked list.
    T popped=list->pop_front();
    //Returning the popped data.
    return popped;
}

//Pop back function to remove an element from the back.
template <class T>
T SimpleVector<T>::pop_back(){
   //Setting our new size.
    arraySize--;
    //Popping a node from the back of the linked list.
    T popped=list->pop_back();
    //Returning the popped data.
    return popped;
}

//Copy constructor that copies a SimpleVector object.
template <class T>
SimpleVector<T>::SimpleVector(SimpleVector &obj){
    //Copying the array size.
    arraySize = obj.arraySize;
    //Creating an empty list.
    list=new LinkedList<T>(0);
    //Copying the linked list.
    for(int i=0;i<obj.size();i++){
        //The push_back function takes data and pushes on a link with that data.
        //By using the overloaded [] operator on our obj, we're getting the data
        //at each link in our obj's linked list. This is how we copy the values.
        push_back(obj[i]);
    }
}

//Destructor definition.
template <class T>
SimpleVector<T>::~SimpleVector(){
    //If we have a nonempty list...
    if (arraySize > 0)
       //We destroy our linked list.
       list->dstryLst();
    //We delete our list pointer.
    delete list;
}

//Subscript error function.
template <class T>
void SimpleVector<T>::subError(){
   cout<<"ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

//Overloaded [] operator.
template <class T>
T &SimpleVector<T>::operator[](const int &sub){
    if(sub<0||sub>=arraySize)
        subError();
    //We return the data at the indexed node.
    return (*list)[sub]->data;
}
#endif