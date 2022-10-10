/* 
 * File:    main.cpp
 * Author:  GeeksforGeeks.org
 * Created: October 6, 2022, 8:30 PM
 * Purpose: Iterator tutorial 4. 
 */

//System Libraries:
#include <iostream>  //I/O Library.
#include<iterator>   //Iterators.
#include<vector>     //Vectors.
using namespace std;

//User Libraries:

//Global Constants.
//Math, Science, Universal, Conversions, High Dimensioned Arrays.

//Function Prototypes:

//Execution Begins Here:
int main(int argc, char** argv) {
    
    //Creating 2 vectors.
    vector<int> arr1 = { 1, 2, 3, 4, 5 };
    vector<int> arr2 = { 10, 20, 30}; 
      
    // Declaring an iterator to a vector.
    vector<int>::iterator ptr = arr1.begin();
     
    // Using advance() to set our position.
    advance(ptr, 3);
      
    // Copying the values of arr2 and inserting them into arr1.
    // Inserting the elements of 1 vector into another using inserter().
    // Inserts arr2 after the 3rd position in arr1.
    copy(arr2.begin(), arr2.end(), inserter(arr1,ptr));
      
    // Displaying our new vector elements.
    cout << "The new vector, after inserting elements, is : ";
    for (int &x : arr1) 
        cout << x << " ";
    
    //Exit the Program - Cleanup.
    return 0;
}