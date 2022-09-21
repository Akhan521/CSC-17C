/* 
 * File: main.cpp
 * Author of driver: Dr. Mark E. Lehr
 * Author of fillAry & prntAry: Aamir Khan
 * Created: 9-12-2022 @ 8:20 PM
 * Purpose:  Triangular Array.
 */

//System Libraries Here.
#include <iostream>  //I/O Library.
using namespace std;

//User Libraries Here.

//Global Constants Only, No Global Variables.
//Like PI, e, Gravity, or conversions.

//Function Prototypes Here.
int  mrkRand(int=1<<15-1);      //PSRNG repeating the same sequence.
int *fillAry(int);              //Randomly fill a 1-D column array.
void prntAry(int *,int);        //Print a 1-D array.
void destroy(int **,int *,int); //Deallocate memory.
//These were written by me:
int**fillAry(int *,int);        //Randomly fill a triangular array.
void prntAry(int **,int *,int); //Print a triangular array.

//Program Execution Begins Here:
int main(int argc, char** argv) {
    //Declare all variables here.
    int *col;      //Column array.
    int **trangl;  //Triangular array.
    int rowSize;   //Number of rows.
    //Input or initialize values here.
    cout<<"Input the number of rows in the array:"<<endl;
    cin>>rowSize;
    //The column array holds how many columns each row has.
    //For ex. col[0] holds how many columns row 0 has.
    col=fillAry(rowSize);        //Dynamic 1-D array.
    trangl=fillAry(col,rowSize); //Dynamic triangular array.
    cout<<endl;
    //Output Located Here.
    cout<<"The Column Array Dimensions:"<<endl;
    prntAry(col,rowSize);
    cout<<"The Triangular Array:"<<endl;
    prntAry(trangl,col,rowSize);
    //Deallocate the array.
    destroy(trangl,col,rowSize);
    //Exit main.
    return 0;
}

//Fill array function to fill a 2D triangular array.
//Input our column array and our row count.
int **fillAry(int *col,int rows){
    //Allocate memory given our rows.
    int **array=new int*[rows];
    //For each row, we allocate an array with a specified number of columns.
    for(int i=0;i<rows;i++){
        array[i]=new int[col[i]]; //Our column sizes are in our col array.
    }
    //Filling our triangular array with 1 digit numbers.
    for(int i=0;i<rows;i++){
        //We use col[i] because it holds how many columns each row has.
        for(int j=0;j<col[i];j++){
            array[i][j]=mrkRand()%9+1; //1 Digit numbers [1-9].
        }
    }
    //Return our triangular array.
    return array;
}

//Print array function to print our triangular array.
//The column array holds how many columns our rows have.
void prntAry(int **array,int *col,int rows){
    for(int i=0;i<rows;i++){
        //We use col[i] because it holds how many columns each row has.
        for(int j=0;j<col[i];j++){
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

//Destroy function to deallocate memory.
void destroy(int **a,int *c,int n){
    //Delete every row of the triangular array.
    for(int i=0;i<n;i++){
        delete []a[i];
    }
    //Delete the pointers.
    delete []a; //Our array of pointers.
    delete []c; //Our column array.
}

//Print array function for a 1D array.
void prntAry(int *a,int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl<<endl;
}

//Fill array function used to fill our column array.
int *fillAry(int n){
    //Allocating memory.
    int *array=new int[n];
    for(int i=0;i<n;i++){
        array[i]=mrkRand()%9+1; //1 Digit numbers [1-9].
    }
    //Returning our array.
    return array;
}

//Random number generator written by Dr.Lehr.
int mrkRand(int seed){
    //X_n+1 = (a*X_n + c) mod m.
    //Where X is the sequence of pseudo-random values.
    //m, 0 < m - modulus.
    //a, 0 < a < m - multiplier.
    //c, 0 ≤ c < m - increment.
    //x_0, 0 ≤ x_0 < m - the seed or starting value.
    unsigned int a=31051;      //Short Prime.
    unsigned int c=997;        //Another Prime.
    unsigned int shrt=1<<15-1; //Range of a positive signed short.
    unsigned int m=1<<31-1;    //Range of a positive signed int.
    static int Xn=30937;       //Short Prime.
    static int cnt=0;          //Initialize the seed.
    //Setting the seed as a short.
    if(cnt==0&&seed<=shrt)
        Xn=seed;
    //Increment the count.
    cnt++;
    //Our sequence definition.
    Xn=(a*Xn+c)%m;
    //Returning our random number.
    return Xn;
}
