/*
 * Simple Vector template class definition.
 * This program adds on 4 different functions. 
 * Author of the 4 functions: Aamir Khan
 */

#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>  //Input and output.
#include <new>       //Needed for the bad_alloc exception.
using namespace std;

template <class T>
class SimpleVector{
//Private members:
private:
   T *aptr;          // To point to the allocated array.
   int arraySize;    // Number of elements in the array.
   void memError();  // Handles memory allocation errors.
   void subError();  // Handles out of range subscripts.
//Public members:
public:
   // Default constructor.
   SimpleVector()
      { aptr = 0; arraySize = 0;}
      
   // Constructor declaration.
   SimpleVector(int);
   
   // Copy constructor declaration.
   SimpleVector(const SimpleVector &);
   
   // Destructor declaration.
   ~SimpleVector();
   
   // Accessor to return the array size.
   int size() const
      { return arraySize; }

   // Accessor to return a specific element.
   T getElementAt(int position);

   // Overloaded [] operator declaration.
   T &operator[](const int &);
   
   //Adding 4 functions:
   void pshFrnt(T);
   void pshBack(T);
   T popFrnt();
   T popBack();
};

//Push front function to insert an element at the front.
template <class T>
void SimpleVector<T>::pshFrnt(T val){
    //Declaring our new size.
   int newSize=arraySize+1;
   //Creating our new array.
   T *newAry=new T[newSize];
   //Adding in the new element at the front.
   newAry[0]=val;
   //Copying over our data.
   for(int i=1;i<newSize;i++){
       newAry[i]=aptr[i-1];
   }
   //Deleting our previous array.
   delete []aptr;
   //Setting our new array.
   aptr=newAry;
   //Updating our size.
   arraySize=newSize;
}

//Push back function to insert an element at the back.
template <class T>
void SimpleVector<T>::pshBack(T val){
   //Declaring our new size.
   int newSize=arraySize+1;
   //Creating our new array.
   T *newAry=new T[newSize];
   //Copying over our data.
   for(int i=0;i<arraySize;i++){
       newAry[i]=aptr[i];
   }
   //Adding in the new element at the end.
   newAry[arraySize]=val;
   //Deleting our previous array.
   delete []aptr;
   //Setting our new array.
   aptr=newAry;
   //Updating our size.
   arraySize=newSize;
}

//Pop front function to remove an element from the front.
template <class T>
T SimpleVector<T>::popFrnt(){
   //Declaring our new size.
   int newSize=arraySize-1;
   //Storing the element that will be popped.
   T popped=aptr[0];
   //Creating our new array.
   T *newAry=new T[newSize];
   //Copying over our data.
   for(int i=1;i<arraySize;i++){
       newAry[i-1]=aptr[i];
   }
   //Deleting our previous array.
   delete []aptr;
   //Setting our new array.
   aptr=newAry;
   //Updating our size.
   arraySize=newSize;
   //Returning the popped element.
   return popped;
}

//Pop back function to remove an element from the back.
template <class T>
T SimpleVector<T>::popBack(){
   //Declaring our new size.
   int newSize=arraySize-1;
   //Storing the element that will be popped.
   T popped=aptr[newSize];
   //Creating our new array.
   T *newAry=new T[newSize];
   //Copying over our data.
   for(int i=0;i<newSize;i++){
       newAry[i]=aptr[i];
   }
   //Deleting our previous array.
   delete []aptr;
   //Setting our new array.
   aptr=newAry;
   //Updating our size.
   arraySize=newSize;
   //Returning the popped element.
   return popped;
}

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************
template <class T>
SimpleVector<T>::SimpleVector(int s){
   arraySize = s;
   // Allocate memory for the array.
   try{
      aptr = new T [s];
   }
   catch(bad_alloc){
      memError();
   }
   // Initialize the array.
   for(int count = 0; count < arraySize; count++)
      *(aptr + count) = 0;
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************
template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj){
   // Copy the array size.
   arraySize = obj.arraySize;
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
   cout<<"ERROR: Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************
template <class T>
void SimpleVector<T>::subError(){
   cout<<"ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************
template <class T>
T SimpleVector<T>::getElementAt(int sub){
   if(sub < 0 || sub >= arraySize)
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
   if(sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}
#endif