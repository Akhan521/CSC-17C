/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Created: October 6, 2022, 6:20 PM
 * Purpose: Sort algorithm tutorial.
 */

//System Libraries:
#include <iostream>  //I/O Library.
#include <algorithm> //Algorithms.
using namespace std;

//User Libraries:

//Global Constants.
//Math, Science, Universal, Conversions, High Dimensioned Arrays.

//Function Prototypes:
void show(int a[], int array_size); //Print an array.

//Execution Begins Here:
int main(int argc, char** argv) {
    //Declaring an unsorted array.
    int a[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
    
    // Size of the array.
    int asize = sizeof(a) / sizeof(a[0]);
    
    cout << "The array before sorting is : \n";
    // Print the array.
    show(a, asize);
  
    // Sort the array.
    sort(a, a + asize);
  
    cout << "\n\nThe array after sorting is :\n";
    // Print the array after sorting.
    show(a, asize);    
    
    //Exit the Program - Cleanup.
    return 0;
}

//Print an array.
void show(int a[], int array_size)
{
    for (int i = 0; i < array_size; ++i)
        cout << a[i] << " ";
}