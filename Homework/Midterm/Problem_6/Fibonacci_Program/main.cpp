/* 
 * File:    main.cpp
 * Author:  Dr. Mark E. Lehr
 * Created: April 21st, 2021, 11:51 AM
 * Purpose: Fibonacci sequence program used to derive 
 *          the Big O() for problem 6 of our midterm.
 */

//System Level Libraries:
#include <iostream>   //I/O Library.
#include <cmath>      //Math Library.
using namespace std;  //Library Scope.

//User Libraries.

//Global Constants.
//Science and Math, Conversions, Higher Dimensions.

//Function Prototypes:
int fibRec(int);  //Fibonacci recursion.
int fibAray(int); //Fibonacci with an array.

//Execution Starts Here:
int main(int argc, char** argv){
    //Set Random Number Seed Here.
    
    //Declare variables.
    int nLoop;
    
    //Initialize variables.
    nLoop=10;
    
    //Map inputs to outputs.
    cout<<"Fibonacci Sequence"<<endl;
    
    //Display the outputs.
    for(int n=0;n<=nLoop;n++){
        cout<<fibAray(n)<<" ";
    }
    cout<<endl<<endl;
    
    //Display the outputs.
    for(int n=0;n<=nLoop;n++){
        cout<<fibRec(n)<<" ";
    }
    cout<<endl<<endl;

    //Exit Stage Right!
    return 0;
}

//Function Implementations:
int fibAray(int n){
    //Create the array.
    int array[n+1];
    array[0]=0; //Setting the first term.
    array[1]=1; //Setting the second term.
    //Looping through and filling the rest of the terms.
    for(int i=2;i<=n;i++){
        //Sum of the previous 2 terms.
        array[i]=array[i-1]+array[i-2];
    }
    //Returning our array.
    return array[n];
}

int fibRec(int n){
    //Base Cases:
    if(n<=0)return 0; //1st term.
    if(n==1)return 1; //2nd term.
    //Recursion:
    return fibRec(n-1)+fibRec(n-2);
}