/* 
 * File:    main.cpp
 * Author:  Dr. Mark E. Lehr
 * Purpose: Searching program used to derive the 
 *          Big O() for problem 1 of our midterm.
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
int  linSrch(int [],int, int);      //Linear search.
int  binSrch(int [],int, int);      //Binary search.
void selSort(int [],int);           //Selection sort.
void copyAry(int [],int [],int);    //To copy our array.

//Program Execution Begins Here:
int main(int argc, char** argv) {
    //Set the random number seed.
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all variables here:
    const int SIZE=100;
    int array[SIZE], //To use for our linear search.
        brray[SIZE]; //To use for our binary search.
    int lowRng=100,  //To control what values we fill
        highRng=200; //our arrays with.
    int perLine=10;  //# of elements per line.
        
    //Filling our arrays:
    fillAry(array,SIZE,highRng,lowRng);
    copyAry(brray,array,SIZE);
    
    //Print the values in our arrays.
    prntAry(array,SIZE,perLine);
    prntAry(brray,SIZE,perLine);
    
    //Sort the array we'll be using for the binary search.
    selSort(brray,SIZE);
    
    //Test the linear search by randomly searching for a value.
    int value=rand()%(highRng-lowRng+1)+lowRng;
    cout<<"Using the Linear Search:"<<endl;
    cout<<"The value "<<value<<" was found at position "
        <<linSrch(array,SIZE,value)<<endl;
    //Test the binary search in the same way.
    cout<<"Using the Binary Search:"<<endl;
    cout<<"The value "<<value<<" was found at position "
        <<binSrch(brray,SIZE,value)<<endl;
    
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

int binSrch(int a[],int n, int val){
    //Initialize end points, which are the indexes.
    int lowEnd=0;
    int highEnd=n-1;
    //Loop until we find our value or not.
    do{
        //Finding the middle.
        int middle=(highEnd+lowEnd)/2;
        if(val==a[middle]) return middle;
        //Updating our end points if we didn't find our value.
        else if(val>a[middle]) lowEnd=middle+1;
        else highEnd=middle-1;
    }while(lowEnd<=highEnd);
    //Not found.
    return -1;
}

int linSrch(int a[],int n, int val){
    //Loop through the entire array.
    for(int indx=0;indx<n;indx++){
        if(val==a[indx]) return indx;
    }
    //Not found.
    return -1;
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