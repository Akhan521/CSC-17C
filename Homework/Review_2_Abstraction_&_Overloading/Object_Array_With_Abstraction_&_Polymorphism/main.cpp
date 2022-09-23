/* 
 * File:    main.cpp
 * Author:  Aamir Khan
 * Created: September 21, 2022, 11:15 PM
 * Purpose: Review 2 - Abstraction, Copy Construction, 
 *          Operator Overloading, and Polymorphism.
 * 
 * This is a continuation on Review 1 - Aggregated Objects.
 */

//System Libraries
#include <iostream>  //I/O Library.
#include <iomanip>   //Formatting.
#include <cstdlib>   //CSTD Library.
#include <ctime>     //Time Library.
using namespace std;

//User Libraries.
#include "PlusTab.h"

//Global Constants.
//Math, Science, Universal, Conversions, High Dimensioned Arrays.

//Function Prototypes.
void prntTab(const Table &); //Prints our table.

//Execution Begins Here!
int main(int argc, char** argv) {
   //Initialize the random number seed.
   srand(static_cast<unsigned int>(time(0)));
   
   //Declare Variables.
   int rows,cols;
   
   //Initialize Variables.
   cout<<"This program creates 2-D arrays composed of 1-D"<<endl;
   cout<<"column arrays. The tables are created from abstract"<<endl;
   cout<<"classes. Operator overloading is also incorporated."<<endl;
   
   cout<<endl;
   cout<<"Input the Rows and Cols:"<<endl;
   cin>>rows>>cols;
   cout<<endl;
   
   //Test out the Tables.
   PlusTab tab1(rows,cols); //Normal constructor.
   PlusTab tab2(tab1);      //Copy constructor.
   PlusTab tab3=tab1+tab2;  //Adding tables together.
   
   //Print Table 1.
   cout<<"Abstracted and Polymorphic Table 1 Size is [Row,Col] = ["
           <<rows<<","<<cols<<"]";
   prntTab(tab1);
   //Print Table 2.
   cout<<"Copy Constructed Table 2 Size is [Row,Col] = ["
           <<rows<<","<<cols<<"]";
   prntTab(tab2);
   //Print Table 3.
   cout<<"Operator Overloaded Table 3 Size is [Row,Col] = ["
           <<rows<<","<<cols<<"]";
   prntTab(tab3);

   //Exit Stage Right.
   return 0;
}

//Print table function.
void prntTab(const Table &a){
    cout<<endl;
    //We display the data in our table object.
    for(int row=0;row<a.getSzRow();row++){
        for(int col=0;col<a.getSzCol();col++){
            cout<<setw(4)<<a.getData(row,col);
        }
        cout<<endl;
    }
    cout<<endl;
}