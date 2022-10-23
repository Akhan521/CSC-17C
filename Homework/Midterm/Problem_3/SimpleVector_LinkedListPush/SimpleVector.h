/* 
 * File:    SimpleVector.h
 * Author:  Dr. Mark E. Lehr
 * Purpose: Simple Vector (Inefficient push implemented.)
 */

#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

// SimpleVector class template:
#include <iostream>  // Input/Output.
#include <new>       // Needed for the bad_alloc exception.
#include <cstdlib>   // Needed for the exit function.
using namespace std;

//Our linked list:
#include "LinkedList.h"

template <class T>
class SimpleVector{
    private:
       LinkedList<T> *aptr;  //Pointer to our Linked List.
       void memError();      // Handles memory allocation errors.
       void subError();      // Handles subscripts out of range.

    public:
       // Constructor declaration.
       SimpleVector(const T &);

       // Copy constructor declaration.
       SimpleVector(const SimpleVector &);

       // Destructor declaration.
       ~SimpleVector();

       // To return the array size.
       int size() const
          { return aptr->cntLst(); }

       // To return a specific element.
       T getElementAt(int position);

       // Overloaded [] operator declaration.
       T &operator[](const int &);
       
       void push(const T &);
};

//***********************************************************
// Push the new value by allocating, copying, then adding   *
// the new value.                                           * 
//***********************************************************

template <class T>
void SimpleVector<T>::push(const T &val){
    //Add a value into the Linked List.
    aptr->addLst(val);
}

//***********************************************************
// Constructor for SimpleVector class with 1 object.        *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(const T &d){
    // Create a new Linked List with 1 object.
    aptr=new LinkedList<T>(d);
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj){
   // Create a new Linked List with the 1st object that we're copying.
   aptr = new LinkedList<T>(obj.aptr->getObj(0));
   // If we have a memory error...
   if (aptr == 0)
      memError();
      
   // Copy the elements of obj's array.
   for(int count = 1; count < obj.size(); count++){
       aptr->addLst(obj.aptr->getObj(count));
   }
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector(){
    // Delete our Linked List.
    delete aptr;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError(){
   cout << "ERROR: Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError(){
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub){
   if (sub < 0 || sub >= aptr->cntLst())
      subError();
   return aptr->getObj(sub);
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub){
   if (sub < 0 || sub >= aptr->cntLst())
      subError();
   return aptr->getPtr(sub);
}

#endif /* SIMPLEVECTOR_H */

