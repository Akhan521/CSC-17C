/* 
 * File:    main.cpp
 * Author:  Dr. Mark E. Lehr
 * Purpose: Sorting program used to derive the 
 *          Big O() for problem 2 of our midterm.
 */

//System Libraries Here:
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries Here:

//Global Constants Only, No Global Variables.
//Like PI, e, Gravity, or conversions.

//Function Prototypes Here:
void prntAry(const int [],int,int); //To print our array.
void fillAry(int [],int,int,int);   //To fill our array.
void bublSrt(int [],int);           //Bubble sort.
void selSort(int [],int);           //Selection sort.
void copyAry(int [],int [],int);    //To copy our array.

//Program Execution Begins Here:
int main(int argc, char** argv) {
    //Set the random number seed.
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all variables here:
    const int SIZE=100;
    int array[SIZE], //To use for our bubble sort.
        brray[SIZE]; //To use for our selection sort.
    int lowRng=100,  //To control what values we fill
        highRng=200; //our arrays with.
    int perLine=10;  //# of elements per line.
        
    //Filling our arrays:
    fillAry(array,SIZE,highRng,lowRng);
    copyAry(brray,array,SIZE);
    
    //Print the values in our arrays.
    prntAry(array,SIZE,perLine);
    prntAry(brray,SIZE,perLine);
    
    //Sort the arrays.
    bublSrt(array,SIZE);
    selSort(brray,SIZE);
    
    //Print the values in our arrays.
    prntAry(array,SIZE,perLine);
    prntAry(brray,SIZE,perLine);

    //Exit stage right.
    return 0;
}

void copyAry(int copyIt[],int source[],int n){
    for(int i=0;i<n;i++){
        copyIt[i]=source[i];
    }
}

void bublSrt(int a[],int n){
    //Keep looping and comparing elements until no swaps can be done.
    bool swap;
    do{
        swap=false;
        //Check the list and swap elements when necessary.
        for(int i=0;i<n-1;i++){
            if(a[i]>a[i+1]){
                //Perform the swap.
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                swap=true;
            }
        }
    //As long as we've swapped, we check again.
    }while(swap);
}

void selSort(int a[],int n){
    //Declare variables.
    int indx,min;
    for(int pos=0;pos<n-1;pos++){
        //Find the smallest element in the list. Then, swap after finding.
        min=a[pos];indx=pos;
        for(int i=pos+1;i<n;i++){
            if(a[i]<min){
                min=a[i];
                indx=i;
            }
        }
        //Perform the swap.
        a[indx]=a[pos];
        a[pos]=min;
    }
}

void fillAry(int a[],int n,int hr,int lr){
    for(int indx=0;indx<n;indx++){
        a[indx]=rand()%(hr-lr+1)+lr;
    }
}

void prntAry(const int a[],int n,int perLine){
    //Print the values in our array.
    cout<<endl<<"The Array Values:"<<endl;
    for(int indx=0;indx<n;indx++){
        cout<<a[indx]<<" ";
        if(indx%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}