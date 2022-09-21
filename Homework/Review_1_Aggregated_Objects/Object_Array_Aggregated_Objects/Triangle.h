/* 
 * File:    Triangle.h
 * Author:  Aamir Khan
 * Created: September 20, 2022, 8:45 PM
 */

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "RowAray.h" //Including our RowAray class.

//Our triangle class:
class Triangle{
    private:
        int szRow;         //Our rows.
        RowAray **records; //Our array of RowAray objects.
    public:
        Triangle(int);  //Constructor.
        ~Triangle();    //Destructor.
        //Getter method for our rows.
        int getSzRow(){return szRow;}
        //Getter method for our indexed data.
        int getData(int,int);
};

//Constructor.
Triangle::Triangle(int rows){
    //Setting our rows.
    szRow=rows;
    //Creating our array of RowAray pointers.
    records=new RowAray *[szRow];
    //Filling our array with RowAray objects.
    for(int i=0;i<szRow;i++){
        //Each row will have a different number of columns.
        records[i]=new RowAray(i+1);
    }
    
}

//Destructor.
Triangle::~Triangle(){
    //Deleting our pointers.
    for(int i=0;i<szRow;i++){
        //Deleting each RowAray object.
        delete records[i];
    }
    //Deleting our array of pointers.
    delete []records;
}

//Getter method for our triangular table data. We utilize the RowAray class's
//getData method which returns an element within a RowAray object.
int Triangle::getData(int row,int col){
    //We return the given element specified by row and col.
    return records[row]->getData(col);
}

#endif /* TRIANGLE_H */

