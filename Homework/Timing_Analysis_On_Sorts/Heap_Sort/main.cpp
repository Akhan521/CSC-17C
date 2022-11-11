/* 
 * File:    main.cpp
 * Author:  GeeksforGeeks.org
 * Created: November 8, 2022, 7:25 PM
 * Purpose: Heap Sort Program Used in Timing Analysis.
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
void print(int *,int,int);   //To print our array.
int *fill(int);              //To fill our array.
void heapify(int *,int,int); //To heapify our array.
void heapSort(int *,int);    //To heapsort our array.

//Execution Begins Here:
int main(int argc, char** argv) {
    //Initialize the Random Number Seed.
    srand(static_cast<unsigned int>(time(0)));
    //Declare Variables.
    int n=80000,perLine=10;
    int beg=time(0);
    for(int i=0;i<1000;i++){
        //Initialize Variables.
        int *array=fill(n);
        //Printing our unsorted array.
        //print(array,n,perLine);
        //Heap sorting our array.
        heapSort(array,n);
        //Printing our sorted array.
        //print(array,n,perLine);
        //Exit the Program - Cleanup.
        delete []array; //Deallocating our array.
    }
    int tot=time(0)-beg;
    cout<<"Total run time = "<<tot<<" seconds.";
    return 0;
}

// To heapify a subtree w/ i as our root node.
// (i is an index and n is the size of our heap.)
void heapify(int *arr, int n, int i){
    // Initialize the largest node as our root.
    int largest = i;
    // The left child.
    int l = 2 * i + 1;
    // The right child.
    int r = 2 * i + 2;
    // If the left child is > than our largest node...
    if (l < n && arr[l] > arr[largest])
        largest = l; //Our left child becomes our largest node.
    // If the right child is > than largest node...
    if (r < n && arr[r] > arr[largest])
        largest = r; //Our right child becomes our largest node.
    // If the largest node is not the root we chose...
    if (largest != i) {
        //We swap the root w/ the child node that's the largest.
        swap(arr[i], arr[largest]);
        // Then, we recursively heapify the affected sub-tree.
        heapify(arr, n, largest);
    }
}
// Heap sort:
void heapSort(int *arr, int n){
    // Build our max-heap. (Rearrange our array.)
    for(int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    // We extract the largest element from the current heap one by one.
    for(int i = n - 1; i > 0; i--){
        // Moving the largest element to the end of our array.
        swap(arr[0], arr[i]);
        // Heapifying our reduced heap for the next iteration.
        heapify(arr, i, 0);
    }
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
        array[i]=rand();
    }
    return array;
}