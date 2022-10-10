/* 
 * File:    main.cpp
 * Author:  GeeksforGeeks.org
 * Created: October 6, 2022, 12:30 PM
 * Purpose: Find algorithm tutorial.
 */

//System Libraries:
#include <iostream>  //I/O Library.
#include <algorithm> //Algorithms.
#include <vector>    //Vectors.
using namespace std;

//User Libraries:

//Global Constants.
//Math, Science, Universal, Conversions, High Dimensioned Arrays.

//Function Prototypes:

//Execution Begins Here:
int main(int argc, char** argv) {
    
    //find(first_iterator, last_iterator, x) – Returns an iterator to the 
    //first occurrence of x in a vector and points to the last address of vector 
    //(vector.end()) if the element is not present in the vector.
    // Initializing vector with array values
    
    //Declaring an array.
    int arr[] = {10, 20, 5, 23 ,42, 20, 15};
    //Determining it's size.
    int n = sizeof(arr)/sizeof(int);
    //Copying the array's contents into a vector.
    vector<int> vect(arr, arr+n);
    
    //Finding all occurrences of 20.
    cout << "Occurrences of 20 in our vector : ";
 
    // Counts the occurrences of 20 from 1st to
    // last element.
    cout << count(vect.begin(), vect.end(), 20);
 
    // find() returns an iterator to the last address if
    // the specified element is not present.
    // If the last address isn't returned, we display 
    // that we've found the value in our vector.
    find(vect.begin(), vect.end(),5) != vect.end()?
        cout << "\nElement found.":
        cout << "\nElement not found.";
    
    //Exit the Program - Cleanup.
    return 0;
}