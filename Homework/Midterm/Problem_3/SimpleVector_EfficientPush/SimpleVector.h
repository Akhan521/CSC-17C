/* 
 * File:    SimpleVector.h
 * Author:  Dr. Mark E. Lehr
 * Purpose: Simple Vector (Efficient push implemented.)
 */

#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

// SimpleVector class template:
#include <iostream>  // Input/Output.
#include <new>       // Needed for the bad_alloc exception.
#include <cstdlib>   // Needed for the exit function.
using namespace std;

template <class T>
class SimpleVector{
    private:
       T *aptr;          // To point to the allocated array.
       int arraySize;    // Number of elements in the array.
       int maxSize;      // Maximum array size (Size limit.)
       void memError();  // Handles memory allocation errors.
       void subError();  // Handles subscripts out of range.

    public:
       // Default constructor.
       SimpleVector()
          { aptr = 0; arraySize = 0; maxSize=0;}

       // Constructor declaration.
       SimpleVector(int);
       
       // Constructor declaration.
       SimpleVector(const T &);

       // Copy constructor declaration.
       SimpleVector(const SimpleVector &);

       // Destructor declaration.
       ~SimpleVector();

       // To return the array size.
       int size() const
          { return arraySize; }
       
       // To return the max array size.
       int mxSize() const
          { return maxSize; }
       
       // To return a specific element.
       T getElementAt(int position);

       // Overloaded [] operator declaration.
       T &operator[](const int &);
       
       void push(T&);
};

//***********************************************************
// Push the new value by allocating, copying, then adding   *
// the new value.                                           * 
//***********************************************************

template <class T>
void SimpleVector<T>::push(T &val){
    //If we've reached the maximum size of the array...
    if(arraySize==maxSize){
        // Double our maximum size.
        maxSize*=2;
        // Declare our new array pointer.
        T *naptr;
        // Allocate memory for the new array using our max size.
        try{
          naptr = new T [maxSize];
        }catch (bad_alloc){
          memError();
        }
        // Fill the array.
        for (int count = 0; count < arraySize; count++){
            naptr[count]=aptr[count];
        }
        // Add our new value and increment the array size.
        naptr[arraySize++]=val;
        // Delete the old array and point to our new array.
        delete []aptr;
        aptr=0;
        aptr=naptr;
    }
    //If we haven't reached the maximum size...
    else{
        // Add our new value and increment the array size.
        aptr[arraySize++]=val;
    }
}

//***********************************************************
// Constructor for SimpleVector class with 1 object.        *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(const T &d){
   arraySize = 1;
   maxSize = 1;
   // Allocate memory for the array.
   try{
      aptr = new T [arraySize];
   }catch (bad_alloc){
      memError();
   }
   // Initialize the array.
   for (int count = 0; count < arraySize; count++)
      aptr[count]=d;
}

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int s){
   arraySize = s;
   maxSize = s;
   // Allocate memory for the array.
   try{
      aptr = new T [s];
   }catch (bad_alloc){
      memError();
   }

   // Initialize the array.
   for (int count = 0; count < arraySize; count++){
       int rdm=rand()%8+2;
       aptr[count]=T(rdm);
   }
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj){
   // Copy the array size.
   arraySize = obj.arraySize;
   maxSize = obj.maxSize;
   // Allocate memory for the array.
   aptr = new T [arraySize];
   if (aptr == 0)
      memError();
      
   // Copy the elements of obj's array.
   for(int count = 0; count < arraySize; count++)
      *(aptr + count) = *(obj.aptr + count);
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector(){
   if (arraySize > 0)
      delete [] aptr;
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
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub){
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

#endif /* SIMPLEVECTOR_H */

