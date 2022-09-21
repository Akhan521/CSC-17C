/* 
 * File:    Table.h
 * Author:  Aamir Khan
 * Created: September 20, 2022, 8:45 PM
 */

#ifndef TABLE_H
#define TABLE_H

#include "RowAray.h" //Including our RowAray class.

//Our table class:
class Table{
    private:
        int szRow;         //Our rows.
        int szCol;         //Our columns.
        RowAray **records; //Our array of RowAray objects.
    public:
        Table(int,int);  //Constructor.
        ~Table();        //Destructor.
        //Getter method for our rows.
        int getSzRow(){return szRow;}
        //Getter method for our columns.
        int getSzCol(){return szCol;}
        //Getter method for our indexed data.
        int getData(int,int);
};

//Constructor.
Table::Table(int rows,int cols){
    //Setting our rows and columns.
    szRow=rows;
    szCol=cols;
    //Creating an array of RowAry pointers.
    records=new RowAray *[szRow];
    //Filling our array with RowAray objects.
    for(int i=0;i<szRow;i++){
        //Each RowAray object will need to hold 
        //as many elements as we have columns.
        records[i]=new RowAray(szCol);
    }
}

//Destructor.
Table::~Table(){
    //Deleting our RowAray objects.
    for(int i=0;i<szRow;i++){
        //Deleting each RowAray object.
        delete records[i];
    }
    //Deleting our array of pointers.
    delete []records;
}

//Getter method for our table data. We utilize the RowAray class's 
//getData method which returns an element within a RowAray object.
int Table::getData(int row,int col){
    //We return the given element specified by row and col.
    return records[row]->getData(col);
}

#endif /* TABLE_H */

