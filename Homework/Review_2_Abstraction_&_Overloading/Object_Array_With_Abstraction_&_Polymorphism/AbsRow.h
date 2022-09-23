/* 
 * File:    AbsRow.h
 * Author:  Aamir Khan
 * Created: September 21, 2022, 11:15 PM
 */

#ifndef ABSROW_H
#define ABSROW_H

//Our abstract row class:
class AbsRow{
    protected:
        int size;     //The size of our array.
        int *rowData; //The data itself.
    public:
        //Virtual getter function for the size.
        virtual int getSize()const = 0;
        //Virtual getter function for the data.
        virtual int getData(int)const = 0;
};

#endif /* ABSROW_H */

