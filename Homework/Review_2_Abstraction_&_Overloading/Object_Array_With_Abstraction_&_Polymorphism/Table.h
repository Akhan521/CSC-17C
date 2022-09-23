/* 
 * File:    Table.h
 * Author:  Aamir Khan
 * Created: September 21, 2022, 11:15 PM
 */

#ifndef TABLE_H
#define TABLE_H

#include "AbsTabl.h" //Including our abstract table class.

//Our table class:
class Table:public AbsTabl{
    public:
        //Constructor.
        Table(unsigned int,unsigned int);
        //Copy Constructor.
        Table(const Table &);
        //Virtual Destructor.
        virtual ~Table();
        //Getter function for the row size.
        int getSzRow()const {return szRow;}
        //Getter function for the col size.
        int getSzCol()const {return szCol;}
        //Getter function for our data.
        int getData(int,int)const;
        //Setter function for our data.
        void setData(int,int,int);
};

//Constructor.
Table::Table(unsigned int rows,unsigned int cols){
    //Setting our rows and columns.
    szRow=rows;
    szCol=cols;
    //Creating our column array pointers.
    columns=new RowAray *[szCol];
    //Filling our array with RowAray objects.
    for(int col=0;col<szCol;col++){
        //Each RowAray object will need to hold 
        //as many elements as we have rows.
        columns[col]=new RowAray(szRow);
    }
}

//Copy Constructor.
Table::Table(const Table &a){
    //Copying the sizes over.
    szRow=a.szRow;
    szCol=a.szCol;
    //Creating our column array pointers.
    columns=new RowAray *[szCol];
    for(int col=0;col<szCol;col++){
        columns[col]=new RowAray(szRow);
    }
    //Copying the data over.
    for(int col=0;col<szCol;col++){
        for(int row=0;row<szRow;row++){
            //Setting our data with the copied data.
            setData(row,col,a.getData(row,col));
        }
    }
}

//Destructor.
Table::~Table(){
    //Deleting our column arrays.
    for(int col=0;col<szCol;col++){
        delete columns[col];
    }
    //Deleting our array of pointers.
    delete []columns;
}

//Getter method for our table data. We utilize the RowAray class's 
//getData method which returns an element within a RowAray object.
int Table::getData(int row,int col)const{
    //Returning the data from the given col and row.
    return columns[col]->getData(row);
}

//Setter function to set our data. We utilize the RowAray class's
//setData method which sets the data of an element in our RowAray object.
void Table::setData(int row,int col,int val){
    //Setting the data in the appropriate column array.
    columns[col]->setData(row,val);
}

#endif /* TABLE_H */

