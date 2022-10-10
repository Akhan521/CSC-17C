/* 
 * File:    main.cpp
 * Author:  GeeksforGeeks.org
 * Created: October 6, 2022, 7:30 PM
 * Purpose: Shuffle algorithm tutorial.
 */

//System Libraries:
#include <bits/stdc++.h> //To demonstrate shuffle()/random_shuffle().
using namespace std;

//User Libraries:

//Global Constants.
//Math, Science, Universal, Conversions, High Dimensioned Arrays.

//Function Prototypes:
void shuffle_array1(int [],int); //Shuffle an array w/ shuffle().
void shuffle_array2(int [],int); //Shuffle an array w/ random_shuffle().

//Execution Begins Here:
int main(int argc, char** argv) {
    
    // Declaring an array.
    int a[] = { 10, 20, 30, 40 };
    int b[] = { 10, 20, 30, 40 };
    
    //Determining our size.
    int n = sizeof(a) / sizeof(a[0]);
    
    //Shuffling w/ shuffle() and printing it.
    cout<<"Using shuffle() : " << endl;
    shuffle_array1(a, n);
    
    //Shuffling w/ random_shuffle() and printing it.
    cout<<"Using random_shuffle() : " << endl;
    shuffle_array2(b,n);
    
    //Exit the Program - Cleanup.
    return 0;
}

// Shuffle an array and print it (w/ shuffle()).
void shuffle_array1(int arr[], int n)
{
    // To obtain a time-based seed.
    unsigned seed = 0;
    
    // Shuffling our array with shuffle().
    shuffle(arr, arr + n, default_random_engine(seed));
 
    // Printing our array.
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// Shuffle an array and print it (w/ random_shuffle()).
void shuffle_array2(int arr[], int n)
{
    // To obtain a time-based seed.
    unsigned seed = 0;
    
    // Shuffling our array with shuffle().
    random_shuffle(arr, arr + n);
 
    // Printing our array.
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}