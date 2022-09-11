/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Created: 8-30-2022 @ 6:20 PM
 * Purpose: Sorting an array of characters.
 */

//System Libraries Here.
#include <iostream>  //Input and output.
#include <cstring>   //strlen() function.
using namespace std;

//User Libraries Here.

//Global Constants Only, No Global Variables.
//Like PI, e, Gravity, or conversions.

//Function Prototypes Here.
int  read(char []);             //Read in a character array.
void sort(char [],int);         //Sort a char array (Bubble sort).
void print(const char [],int);  //Print a char array.

//Program Execution Begins Here.
int main(int argc, char** argv) {
    //Declare all Variables Here.
    const int SIZE=80;  //Larger than needed.
    char array[SIZE];   //Character array larger than needed.
    int sizeIn,sizeDet; //Size inputted and size determined.
    
    //Input the size of the array you are sorting.
    cout<<"Read in a 1 dimensional array of characters and sort"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of characters and determine it's size.
    cout<<"Now read the Array"<<endl;  
    sizeDet=read(array);  //Determine it's size.
    //Compare the size input vs. size detected and sort if same.
    //Else, output different size to sort.
    if(sizeDet==sizeIn){
        sort(array,sizeIn);  //Sort the array.
        print(array,sizeIn); //Print the array.
    }else{
        cout<<(sizeDet<sizeIn?"Input size less than specified.":
               "Input size greater than specified.")<<endl;
    }
    //Exit stage right.
    return 0;
}
//Read function.
int read(char a[]){
    cin>>a;
    return strlen(a); //Returns the size/length of the array passed in.
}
//Sort function.
void sort(char a[], int n){
    bool swap;
    do{
        swap = false;
        for(int i=0;i<n-1;i++){
            if(a[i]>a[i+1]){
                //Logic swap.
                a[i]  =a[i]^a[i+1];
                a[i+1]=a[i]^a[i+1];
                a[i]  =a[i]^a[i+1];
                swap = true;
            }
        }
    }while(swap);
}
//Print function.
void print(const char a[], int n){
    for(int i=0;i<n;i++){
        cout <<a[i];
    }
    cout<<endl;
}