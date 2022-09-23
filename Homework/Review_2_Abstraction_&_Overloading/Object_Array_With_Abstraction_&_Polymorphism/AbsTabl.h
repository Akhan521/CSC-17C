/* 
 * File:    AbsTabl.h
 * Author:  Aamir Khan
 * Created: September 21, 2022, 11:15 PM
 * 
 * As opposed to making our table out of row arrays,
 * we create our table out of column arrays this time.
 * For ex. if we had to create a 3 x 4 table, we would
 * use 4 column arrays with 3 elements each. Before, we
 * would have used 3 row arrays with 4 elements each.
 */

#ifndef ABSTABL_H
#define ABSTABL_H

#include "RowAray.h" //Including our row array class.

//Our abstract table class:
class AbsTabl{
    protected:
        int szRow;         //Our row size.
        int szCol;         //Our column size.
        RowAray **columns; //Our column arrays.
    public:
        //Virtual getter function for the row size.
        virtual int getSzRow()const = 0;
        //Virtual getter function for the col size.
        virtual int getSzCol()const = 0;
        //Virtual getter function for our data.
        virtual int getData(int,int)const = 0;
};


#endif /* ABSTABL_H */

