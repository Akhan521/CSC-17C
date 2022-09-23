/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Created: September 22, 2022, 9:15 PM
 * Purpose: Review 3 - Templated Objects.
 */

//System Libraries
#include <iostream>  //I/O Library.
#include <iomanip>   //Formatting.
using namespace std;

//User Libraries.
#include "Table.h"

//Global Constants.
//Math, Science, Universal, Conversions, High Dimensioned Arrays.

//Function Prototypes.
template<class T>
void prntRow(T *,int);          //Prints our RowAray objects.
template<class T>
void prntTab(const Table<T> &); //Prints our Table objects.

//Execution Begins Here!
int main(int argc, char** argv) {
   //Initialize the random number seed.
   srand(static_cast<unsigned int>(time(0)));
   
   //Declare Variables.
   int rows,cols;
   
   //Initialize Variables.
   cout<<"Input the Rows and Columns for the Row and Table Arrays:"<<endl;
   cin>>rows>>cols;
   cout<<endl;
   
   //Test out RowAray objects with integers and floats.
   RowAray<int> a(rows); RowAray<float> b(cols);
   cout<<"Test The Integer RowAray Object With Rows As Our Size:"<<endl;
   prntRow(&a,rows);
   cout<<"Test The Float RowAray Object With Columns As Our Size:"<<endl;
   prntRow(&b,cols);
   
   //Test out Table objects with floats.
   Table<float> tab1(rows,cols); //Normal constructor.
   Table<float> tab2(tab1);      //Copy constructor.
   Table<float> tab3=tab1+tab2;  //Adding 2 tables together.
   
   cout<<"Float Table Size is [Row,Col] = Table 1 + Table 2 ["
           <<rows<<","<<cols<<"]";
   //Printing table 1:
   cout<<endl<<"Table 1:"<<endl;
   prntTab(tab1);
   //Printing table 2:
   cout<<"Table 2 (Copy of Table 1):"<<endl;
   prntTab(tab2);
   //Printing table 3:
   cout<<"Table 3 (Addition of Table 1 and Table 2):"<<endl;
   prntTab(tab3);
   
   //Exit Stage Right.
   return 0;
}

//Print function for our RowAray objects.
template<class T>
void prntRow(T *a,int perLine){
    cout<<fixed<<setprecision(1)<<showpoint<<endl;
    for(int i=0;i<a->getSize();i++){
        cout<<a->getData(i)<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

//Print function for our Table objects.
template<class T>
void prntTab(const Table<T> &a){
    cout<<fixed<<setprecision(1)<<showpoint<<endl;
    for(int row=0;row<a.getSzRow();row++){
        for(int col=0;col<a.getSzCol();col++){
            cout<<setw(8)<<a.getData(row,col);
        }
        cout<<endl;
    }
    cout<<endl;
}