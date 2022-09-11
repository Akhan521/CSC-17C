/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Created: 8-30-2022 @ 6:30 PM
 * Purpose: Finding the max, min, and sum of an array.
 */

//System Libraries Here.
#include <iostream> //cin and cout.
using namespace std;

//User Libraries Here.

//Global Constants Only, No Global Variables.

//Function Prototypes Here.
void read(int [],int);                    //Read in an integer array.
int  stat(const int [],int,int &,int &);  //For array statistics.
void print(const int [],int,int,int,int); //Printing statistics.

//Program Execution Begins Here.
int main(int argc, char** argv) {
    //Declare all Variables Here.
    const int SIZE=80;
    int array[SIZE];
    int sizeIn,sum,min,max;
    
    //Input the size of the array you are operating on.
    cout<<"Read in a 1 dimensional array of integers to find sum/min/max"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of integers.
    cout<<"Now read the Array"<<endl;
    read(array,sizeIn); //Read in the array of integers.
    
    //Find the sum, max, and min.
    sum=stat(array,sizeIn,max,min);  //Find the sum, max and min.
    
    //Print the results.
    print(array,sizeIn,sum,max,min); //Print the array, sum, max and min.
    
    //Exit.
    return 0;
}
//Read function.
void read(int a[],int n){
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
}
//Stats function. Returns the sum of the array.
//max and min are variables passed by reference.
int stat(const int a[],int size,int &max,int &min){
    int sum = 0;
    for(int i=0;i<size;i++){ //Calculate the sum.
        sum+=a[i];
    }
    //Finding the max and min.
    max = min = a[0];        //Initializing our variables.
    for(int i=1;i<size;i++){ //Find min and max.
        if(a[i]>max) 
           max = a[i];
        if(a[i]<min) 
           min = a[i];
    }
    return sum;
}
//Print function. Displays array statistics.
void print(const int a[],int size,int sum,int max,int min){
    for(int i=0;i<size;i++){
        cout<< "a["<<i<<"] = "<<a[i]<<endl;
    }
    cout<< "Min  = "<< min<<endl;
    cout<< "Max  = "<< max<<endl;
    cout<< "Sum  = "<< sum<<endl;
}