/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Created: September 20, 2022, 8:45 PM
 * Purpose: Review 1 - Aggregated Objects.
 */

//System Libraries
#include <iostream>  //I/O Library.
using namespace std;

//User Libraries.
#include "Table.h"
#include "Triangle.h"
//Global Constants.
//Math, Science, Universal, Conversions, High Dimensioned Arrays.

//Function Prototypes.
void prntRow(RowAray *,int); //Prints our RowAray object.
void prntTab(Table *);       //Prints our Table object.
void prntTri(Triangle *);    //Prints our Triangle object.

//Execution Begins Here!
int main(int argc, char** argv) {
   //Initialize the random seed.
   srand(static_cast<unsigned int>(time(0)));
   
   //Declare Variables.
   int rows,cols,perLine;
   
   //Read in Rows and Cols.
   cout<<"Input Rows and Cols:"<<endl;
   cin>>rows>>cols;
   perLine=cols/2; //How many elements per line we display.
   cout<<endl;
   
   //Test out the RowAray.
   RowAray row(cols);
    
   //Print the RowAray.
   cout<<"The Row Array Size = "<<row.getSize()
       <<" Printed "<<perLine<<" Per Line.";
   prntRow(&row,perLine);
   
   //Test out the Table.
   Table tab(rows,cols);
   
   //Print the Table.
   cout<<"The Table Size is [Row,Col] = ["<<rows<<","<<cols<<"]";
   prntTab(&tab);
   
   //Test out the Triangular Table.
   Triangle tri(rows);
   
   //Print the Triangular Table.
   cout<<"The Triangular Table Size is [Row,Row] = ["<<rows<<","<<rows<<"]";
   prntTri(&tri);

   //Exit Stage Right.
   return 0;
}

//Print function for our RowAray object.
void prntRow(RowAray *a,int perLine){
    cout<<endl;
    for(int i=0;i<a->getSize();i++){
        cout<<a->getData(i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

//Print function for our Table object.
void prntTab(Table *a){
    cout<<endl;
    for(int row=0;row<a->getSzRow();row++){
        for(int col=0;col<a->getSzCol();col++){
            cout<<a->getData(row,col)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

//Print function for our Triangle object.
void prntTri(Triangle *a){
    cout<<endl;
    for(int row=0;row<a->getSzRow();row++){
        for(int col=0;col<=row;col++){
            cout<<a->getData(row,col)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}