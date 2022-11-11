/* 
 * File:    main.cpp
 * Author:  Dr. Mark E. Lehr
 * Created: April 2, 2021, 1:20 PM
 * Purpose: Merge Sort Program Used in Timing Analysis.
 */

//System Libraries:
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Our data structure.
struct Data{
    int size;     //Our array size.
    int *sortit;  //Our sorted array.
    int *working; //Our working array for operations.
};

//Global Constants.

//Function Prototypes:
Data *fill(int);                //Fill the array structure.
void print(Data *,int);         //Print the array.
void merge(Data *,int,int,int); //Merge 2 arrays.
void mrgSort(Data *,int,int);   //Merge sort via recursion.
void destroy(Data *);           //Deallocate memory.

//Execution Begins Here:
int main(int argc, char** argv) {
    //Set the random number generator.
    srand(static_cast<unsigned int>(time(0)));
    //Allocate the arrays.
    int n=100,perLine=10;
    Data *a=fill(n);
    //Printing our unsorted array.
    print(a,perLine);
    //Sort the arrays.
    mrgSort(a,0,a->size);
    //Printing our sorted array.
    print(a,perLine);
    //Deallocate our data.
    destroy(a);
    //Exit stage right.
    return 0;
}

void destroy(Data *a){
    //Deallocate data elements.
    delete []a->sortit;
    delete []a->working;
    delete a;
}

void mrgSort(Data *a,int beg,int end){
    //Find the midpoint. 
    int center=(beg+end)/2;
    //If there is more than 1 element, we sort the left half.
    if((center-beg)>1) mrgSort(a,beg,center);
    //If there is more than 1 element, we sort the right half.
    if((end-center)>1) mrgSort(a,center,end);
    //We merge the 2 sorted arrays into 1 larger sorted array.
    merge(a,beg,center,end);
}

void merge(Data *a,int beg,int nlow,int nhigh){
    //Create a merged array:
    int span=nhigh-beg;     //Our span (The # of elements in our array.)
    int cntl=beg,cnth=nlow; //Independent counters.
    //Fill the array.
    for(int i=0;i<span;i++){
        //If we've used all of the values in the lower half, we fill the array
        //with the rest of the higher half.
        if(cntl==nlow){
            a->working[i]=a->sortit[cnth++];
        }
        //If we've used all of the values in the higher half, we fill the array
        //with the rest of the lower half.
        else if(cnth==nhigh){
            a->working[i]=a->sortit[cntl++];
        }
        //If the value in the lower half is smaller, we store that value.
        else if(a->sortit[cntl]<a->sortit[cnth]){
            a->working[i]=a->sortit[cntl++]; //Fill with the lower end value.
        }else{
            a->working[i]=a->sortit[cnth++]; //Fill with the higher end value.
        }
    }
    //Copying the working array to our sorted array.
    for(int i=0;i<span;i++){
        a->sortit[beg+i]=a->working[i];
    }
}

void print(Data *a,int perLine){
    cout<<endl;
    for(int i=0;i<a->size;i++){
        cout<<a->sortit[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

Data *fill(int n){
    //Allocate memory.
    Data *data=new Data;
    data->size=n;
    data->sortit=new int[n];
    data->working=new int[n];
    for(int i=0;i<n;i++){
        data->sortit[i]=rand()%90+10;
    }
    return data;
}