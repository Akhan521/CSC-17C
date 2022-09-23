/* 
 * File:    Table.h
 * Author:  Aamir Khan
 * Created: September 22, 2022, 9:15 PM
 */

#ifndef TABLE_H
#define TABLE_H

#include "RowAray.h" //Including our RowAray class.

//Our template table class:
template<class T>
class Table{
    protected:
        int szRow;            //Our row size.
        int szCol;            //Our column size.
        RowAray<T> **columns; //Our column arrays.
    public:
        //Constructor.
        Table(unsigned int,unsigned int);
        //Copy Constructor.
        Table(const Table<T> &);
        //Destructor.
        virtual ~Table();
        //Getter method for our row size.
        int getSzRow()const {return szRow;}
        //Getter method for our col size.
        int getSzCol()const {return szCol;}
        //Getter method for our data.
        T getData(int,int)const;
        //Setter method for our data.
        void setData(int,int,T);
        //Overloaded + operator to add tables.
        Table<T> operator+(const Table<T> &);
};

//Constructor.
template<class T>
Table<T>::Table(unsigned int rows,unsigned int cols){
    //Setting our sizes.
    szRow=rows;
    szCol=cols;
    //Creating our column array pointers.
    columns=new RowAray<T> *[szCol];
    //Filling our array with RowAray objects. 
    for(int col=0;col<szCol;col++){
        //Each column array needs as many elements
        //as we have rows, so we account for this.
        columns[col]=new RowAray<T>(szRow);
    }
}

//Copy Constructor.
template<class T>
Table<T>::Table(const Table<T> &a){
    //Setting our sizes.
    szRow=a.szRow;
    szCol=a.szCol;
    //Creating our column arrays.
    columns=new RowAray<T> *[szCol];
    //Filling our array with RowAray objects. 
    for(int col=0;col<szCol;col++){
        //Each column array needs as many elements
        //as we have rows, so we account for this.
        columns[col]=new RowAray<T>(szRow);
    }
    //Copying the data over.
    for(int col=0;col<szCol;col++){
        for(int row=0;row<szRow;row++){
            //Setting the copied data.
            setData(row,col,a.getData(row,col));
        }
    }
}

//Destructor.
template <class T>
Table<T>::~Table(){
    //Deleting our RowAray objects.
    for(int col=0;col<szCol;col++){
        //Deleting each column array.
        delete columns[col];
    }
    //Deleting our array of pointers.
    delete []columns;
}

//Getter method for our table data. We utilize the RowAray class's 
//getData method which returns an element within a RowAray object.
template <class T>
T Table<T>::getData(int row,int col)const{
    //We return the given element specified by col and row.
    return columns[col]->getData(row);
}

//Setter method for our data. We utilize the RowAray class's setData
//method which sets the data of an element within a RowAray object.
template<class T>
void Table<T>::setData(int row,int col,T val){
    //Setting the appropriate element specified by the col and row.
    columns[col]->setData(row,val);
}

//Overloaded + operator to add tables of the same sizes together.
template<class T>
Table<T> Table<T>::operator+(const Table<T> &a){
    //Creating a table object and setting it's size.
    Table<T> table(szRow,szCol);
    //Storing the sums:
    for(int col=0;col<szCol;col++){
        for(int row=0;row<szRow;row++){
            //Adding the left operand's data with the right operand's
            //data, and storing the sum in our new table object.
            table.setData(row,col,getData(row,col)+a.getData(row,col));
        }
    }
    //Returning our table.
    return table;
}

#endif /* TABLE_H */

