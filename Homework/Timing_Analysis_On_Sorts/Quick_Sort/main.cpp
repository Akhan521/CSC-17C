/* 
 * File:    main.cpp
 * Author:  GeeksforGeeks.org
 * Created: November 8, 2022, 7:00 PM
 * Purpose: Quick Sort Program Used in Timing Analysis.
 */

//System Libraries:
#include <iostream>  //I/O Library.
#include <cstdlib>   //CSTD Library.
#include <ctime>     //Time Library.
using namespace std;

//User Libraries:

//Global Constants.
//Math, Science, Universal, Conversions, High Dimensioned Arrays.

//Function Prototypes:
int partition(int *,int,int);  //To partition our array around a pivot.
void quickSort(int *,int,int); //To quick sort our array.
int *fill(int);                //To fill our array.
void print(int *,int,int);     //To print our array.

//Execution Begins Here:
int main(int argc, char** argv) {
    //Initialize the Random Number Seed.
    srand(static_cast<unsigned int>(time(0)));
    //Declare Variables.
    int n=100,perLine=10;
    //Initialize Variables.
    int *array=fill(n);
    //Print our unsorted array.
    print(array,n,perLine);
    //Sort our array.
    quickSort(array,0,n-1);
    //Print our sorted array.
    print(array,n,perLine);
    //Exit the Program - Cleanup.
    delete []array; //Deallocating our array.
    return 0;
}

int *fill(int n){
    int *array=new int[n];
    for(int i=0;i<n;i++){
        array[i]=rand()%90+10;
    }
    return array;
}

void print(int *arr, int n, int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int partition(int *arr, int start, int end){
    //Choosing our pivot.
    int pivot = arr[start];
    //Our counter variable.
    int count = 0;
    for(int i = start + 1; i <= end; i++){
        if(arr[i] <= pivot)
            count++;
    }
    //Finding the correct position of our pivot.
    int pivotIndex = start + count;
    //Putting the pivot into it's correct position.
    swap(arr[pivotIndex], arr[start]);
    //Sorting our elements with respect to the pivot.
    int i = start, j = end;
    while(i < pivotIndex && j > pivotIndex){
        //Finding the first value that is <= than our pivot.
        while(arr[i] <= pivot){
            i++;
        }
        //Finding the first value that is > our pivot.
        while(arr[j] > pivot){
            j--;
        }
        //If we have valid indices, we swap the values at those indices.
        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(int *arr, int start, int end){
    // Base case.
    if(start >= end)
        return;
    // Partitioning the array.
    int p = partition(arr, start, end);
    // Sorting the left part.
    quickSort(arr, start, p - 1);
    // Sorting the right part.
    quickSort(arr, p + 1, end);
}