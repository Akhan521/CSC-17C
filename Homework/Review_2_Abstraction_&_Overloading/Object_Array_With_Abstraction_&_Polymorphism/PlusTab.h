/* 
 * File:    PlusTab.h
 * Author:  Aamir Khan
 * Created: September 21, 2022, 11:15 PM
 */

#ifndef PLUSTAB_H
#define PLUSTAB_H

#include "Table.h" //Including our table class.

//Our plus table class: (Overloads the + operator).
class PlusTab:public Table{
    public:
        //Constructor. (It calls the table class's constructor).
        PlusTab(unsigned int r,unsigned int c):Table(r,c){};
        //Overloaded + operator to add tables.
        PlusTab operator+(const PlusTab &);
};

//Overloaded + operator to add tables.
PlusTab PlusTab::operator+(const PlusTab &a){
    //Creating an object to hold our modified data.
    PlusTab table(szRow,szCol);
    //Adding the data together and storing it in our new object.
    for(int col=0;col<szCol;col++){
        for(int row=0;row<szRow;row++){
            //We set the object's data with the added data.
            //We take the left operand's data and add it to 
            //the right operand's data. The sum is stored.
            table.setData(row,col,getData(row,col)+a.getData(row,col));
        }
    }
    //Returning our plus table object.
    return table;
}

#endif /* PLUSTAB_H */

