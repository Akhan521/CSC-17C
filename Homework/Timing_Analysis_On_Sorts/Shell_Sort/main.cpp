/* 
 * File:    main.cpp
 * Author:  GeeksforGeeks.org
 * Created: November 8, 2022, 7:40 PM
 * Purpose: Shell Sort Program Used in Timing Analysis.
 */

//System Libraries:
#include <iostream>  //I/O Library.
#include <cstdlib>   //CSTD Library.
using namespace std;

//User Libraries:

//Global Constants.
//Math, Science, Universal, Conversions, High Dimensioned Arrays.

//Function Prototypes:
void print(int *,int,int);   //To print our array.
int *fill(int);              //To fill our array.
void shellSort(int *,int);   //To shell sort our array.

//Execution Begins Here:
int main(int argc, char** argv) {
    //Initialize the Random Number Seed.
    srand(static_cast<unsigned int>(time(0)));
    //Declare Variables.
    int n=100,perLine=10;
    //Initialize Variables.
    int *array=fill(n);
    //Printing our unsorted array.
    print(array,n,perLine);
    //Heap sorting our array.
    shellSort(array,n);
    //Printing our sorted array.
    print(array,n,perLine);
    //Exit the Program - Cleanup.
    delete []array; //Deallocating our array.
    return 0;
}

void print(int *arr, int n, int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *fill(int n){
    int *array=new int[n];
    for(int i=0;i<n;i++){
        array[i]=rand()%90+10;
    }
    return array;
}

void shellSort(int *arr, int n){
    // Starting with a big gap size, then reducing the gap as we sort.
    for(int gap = n/2; gap > 0; gap /= 2){
        // Using a gapped insertion sort for this gap size.
        for(int i = gap; i < n; i++){
            // Storing the current element in temp.
            int temp = arr[i];
            // We shift the earlier, gap-sorted elements up until the correct
            // location for arr[i] is found.
            int j;           
            for(j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap]; 
            // We put temp (The original arr[i].) in its correct location.
            arr[j] = temp;
        }
    }
}