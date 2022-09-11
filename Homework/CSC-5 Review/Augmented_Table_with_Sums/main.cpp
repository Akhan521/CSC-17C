/* 
 * File:     main.cpp
 * Author:   Aamir Khan
 * Created:  8-30-2022 @ 8:20 PM
 * Purpose:  Row sums, column sums, and grand sum of an array.
 * We're augmenting our table to hold an additional row and column.
 * These additions will be used to hold our row sums and column sums.
 * We're also going to hold the grand sum of all elements in our table.
 */

//System Libraries Here.
#include <iostream> //cin and cout.
#include <iomanip>  //setw(10).
using namespace std;

//User Libraries Here.

//Global Constants Only, No Global Variables.
//Allowed like PI, e, Gravity, conversions, array dimensions necessary.
const int COLMAX=80;  //Max Columns, much larger than needed.

//Function Prototypes Here.
void read(int [][COLMAX],int &,int &);                //Read in a 2D array.
void sum(const int [][COLMAX],int,int,int[][COLMAX]); //Sums rows, cols, and all elements.
void print(const int [][COLMAX],int,int,int);         //Prints our table.

//Program Execution Begins Here.
int main(int argc, char** argv) {
    //Declare all Variables Here.
    const int ROW=80;           //Max Rows, much larger than needed,
    int array[ROW][COLMAX]={};  //Declare our original array.
    int augAry[ROW][COLMAX]={}; //Declare our augmented table -> row+1 & col+1.
    int row,col;                //To hold our rows and columns.            
    
    //Input the original table.
    read(array,row,col);
    
    //Augment the original table with the sums.
    sum(array,row,col,augAry);
    
    //Output the original array.
    cout<<endl<<"The Original Array"<<endl;
    print(array,row,col,10);      //setw(10)
    
    //Output the augmented array.
    cout<<endl<<"The Augmented Array"<<endl;
    //The augmented table holds an additional row and column.
    print(augAry,row+1,col+1,10); //setw(10)
    
    //Exit.
    return 0;
}
//Read function. Reads in a 2D array and stores the number of
//rows and columns in their own variables. 
void read(int a[][COLMAX],int &row,int &col){
    cout<<"Input a table and output the Augment row,col and total sums.\n";
    cout<<"First input the number of rows and cols. <20 for each\n";
    cin>>row>>col;
    //Filling our table.
    cout<<"Now input the table.\n";
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>a[i][j];
        }
    }
}
//Sum function. Calculates our row, column, and grand sums.
void sum(const int a[][COLMAX],int row,int col,int b[][COLMAX]){
    //Calculating our sums.
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            //Copying the values into our augmented table.
            b[i][j]=a[i][j];
            //Row sums:
            b[i][col]+=b[i][j];
            //Column sums:
            b[row][j]+=b[i][j];
            //Grand sum (Last row and last column):
            b[row][col]+=b[i][j];
        }   
    }
}
//Print function.
void print(const int a[][COLMAX],int row,int col,int spcing){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<setw(spcing)<<a[i][j];
        }
        cout<<endl;
    }
}